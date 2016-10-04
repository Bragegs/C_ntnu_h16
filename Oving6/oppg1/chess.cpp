#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <functional>

using namespace std;

class ChessBoard {
public:
  enum class Color { WHITE,
                     BLACK };

  class Piece {
  public:
    Piece(Color color) : color(color) {}
    virtual ~Piece() {}

    Color color;
    
    std::string color_string() const {
      if (color == Color::WHITE)
        return "white";
      else
        return "black";
    }
    
    std::string color_string_short() const {
      if (color == Color::WHITE)
        return " w";
      else
        return " b";
    }

    /// Return color and type of the chess piece
    virtual std::string type() const = 0;
    virtual std::string type_short() const = 0;

    /// Returns true if the given chess piece move is valid
    virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const = 0;
    
  };

  class King : public Piece {
    
    public:
       
     King(ChessBoard::Color color) : Piece(color) {}
     
     string type() const override{
       return Piece::color_string() + " king";
     }
     
     string type_short() const override{
       return Piece::color_string_short() + "K ";
     }
     
     bool valid_move(int from_x, int from_y, int to_x, int to_y) const override{
         
       vector<int> move = {from_x, from_y, to_x, to_y};
       
       //check if x or y out of (chessboard)bounds
       for (auto &step : move) {
         if (step < 0 || step > 8) {
           return false; 
         }
       }
       
       //check if the move is not really a move
       if ( move.at(0) == move.at(2) && move.at(1) == move.at(3) ){
         return false;
       }
  
       
       if ( abs( move.at(0) - move.at(2) ) == 1 || move.at(0) == move.at(2) ) { // king can only move 1 x left/right or stay in same x
         
         if ( abs( move.at(1) - move.at(3) ) == 1 || move.at(1) == move.at(3) ) { // king can only move 1 y down/up or stay in same y
             return true;
         }
         
       }

       return false;
     }
     
  };

  class Knight : public Piece {
    // missing implementations
    public:
    
    Knight(ChessBoard::Color color) : Piece(color) {}
    
    string type() const override{
      return Piece::color_string() + " knight";
    }
    
    string type_short() const override{
      return Piece::color_string_short() + "Kn";
    }
    
    bool valid_move(int from_x, int from_y, int to_x, int to_y) const override{
     
     vector<int> move = {from_x, from_y, to_x, to_y};
     
     for (auto &step : move) {
        if (step < 0 || step > 8) {
          return false; 
        }
     }
     
     //check if the move is not really a move
     if ( move.at(0) == move.at(2) && move.at(1) == move.at(3) ){
       return false;
     }
     
     int abs_x_move = abs( move.at(0) - move.at(2) );
     int abs_y_move = abs( move.at(1) - move.at(3) );
     
     if ( abs_x_move == 1 ||  abs_x_move == 2){ //knight can only move 1 or 2 x('es) left/right
       
       if ( abs_y_move == 1 || abs_y_move == 2){//knight can only move 1 or 2 y('s) down/up
         return true;
       }
       
     } 
     
     return false;
        
    }
    
  };
  
 

  ChessBoard() {
    // Initialize the squares stored in 8 columns and 8 rows:
    squares.resize(8);
    for (auto &square_column : squares)
      square_column.resize(8);
  }

  /// 8x8 squares occupied by 1 or 0 chess pieces
  vector<vector<unique_ptr<Piece>>> squares;

  function<void(const Piece &piece, const string &from, const string &to)> on_piece_move;
  function<void(const Piece &piece, const string &square)> on_piece_removed;
  function<void(Color color)> on_lost_game;
  function<void(const Piece &piece, const string &from, const string &to)> on_piece_move_invalid;
  function<void(const string &square)> on_piece_move_missing;
  function<void()> after_piece_move;

  /// Move a chess piece if it is a valid move
  bool move_piece(const std::string &from, const std::string &to) {
    int from_x = from.at(0) - 'a';
    int from_y = stoi(string() + from.at(1)) - 1;
    int to_x = to.at(0) - 'a';
    int to_y = stoi(string() + to.at(1)) - 1;

    auto &piece = squares.at(from_x).at(from_y);
    if (piece) {
      if (piece->valid_move(from_x, from_y, to_x, to_y)) {
        if (on_piece_move)
          on_piece_move(*piece, from, to);
        auto &piece_at_to_pos = squares.at(to_x).at(to_y);
        if (piece_at_to_pos) {
          if (piece->color != piece_at_to_pos->color) {
            if (on_piece_removed)
              on_piece_removed(*piece_at_to_pos, to);
            if (auto king = dynamic_cast<King *>(piece_at_to_pos.get())) {
              if (on_lost_game)
                on_lost_game(king->color);
            }
          } else {
            // piece in the from square has the same color as the piece in the to square
            if (on_piece_move_invalid)
              on_piece_move_invalid(*piece, from, to);
            return false;
          }
        }
        piece_at_to_pos = move(piece);
        if(after_piece_move)
          after_piece_move();
        return true;
      } else {
        if (on_piece_move_invalid)
          on_piece_move_invalid(*piece, from, to);
        return false;
      }
    } else {
      if(on_piece_move_missing)
        on_piece_move_missing(from);
      return false;
    }
  }
  

};

class ChessBoardPrint {
   
 public:
   ChessBoardPrint(ChessBoard &board) {
     
     board.on_piece_move = [](const ChessBoard::Piece &piece, const string &from, const string &to) {
       cout << piece.type() << " is moving from " << from << " to " << to << endl;
     };
     board.on_piece_removed = [](const ChessBoard::Piece &piece, const string &square) {
       cout << piece.type() << " is being removed from " << square << endl;
     };
     board.on_lost_game = [](ChessBoard::Color color) {
       if (color == ChessBoard::Color::WHITE)
         cout << "Black";
       else
         cout << "White";
       cout << " won the game" << endl;
     };
     board.on_piece_move_invalid = [](const ChessBoard::Piece &piece, const string &from, const string &to) {
       cout << "can not move " << piece.type() << " from " << from << " to " << to << endl;
     };
     board.on_piece_move_missing=[](const string &square) {
       cout << "no piece at " << square << endl;
     };
     
     board.after_piece_move = [&board]() {
       int length = 8;
       cout << "    a    b    c    d    e    f    g    h " << endl;
       for(int i=0; i < length; ++i){
         cout << "(" << i+1 << ")";
         for(int j=0; j < length; ++j){
           if (board.squares.at(j).at(i)){
             cout << board.squares.at(j).at(i)->type_short();
           }else{
             cout << " [] ";
           }
           cout << " ";
         }
         cout << " " << endl;
       }
     };
   }
   
 };
 
int main() {
  ChessBoard board;
  ChessBoardPrint print(board);


  //board.squares.at(4).at(0) is the same as board.squares[4][0] but with range check
  board.squares.at(4).at(0) = make_unique<ChessBoard::King>(ChessBoard::Color::WHITE);
  board.squares.at(1).at(0) = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);
  board.squares.at(6).at(0) = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);

  board.squares.at(4).at(7) = make_unique<ChessBoard::King>(ChessBoard::Color::BLACK);
  board.squares.at(1).at(7) = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);
  board.squares.at(6).at(7) = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);

  cout << "Invalid moves:" << endl;
  board.move_piece("e3", "e2");
  board.move_piece("e1", "e3");
  board.move_piece("b1", "b2");
  cout << endl;

  cout << "A simulated game:" << endl;
  board.move_piece("e1", "e2");
  board.move_piece("g8", "h6");
  board.move_piece("b1", "c3");
  board.move_piece("h6", "g8");
  board.move_piece("c3", "d5");
  board.move_piece("g8", "h6");
  board.move_piece("d5", "f6");
  board.move_piece("h6", "g8");
  board.move_piece("f6", "e8");
}
