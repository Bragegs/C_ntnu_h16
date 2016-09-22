#include <iostream>
#include <vector>

// Lag et lite program:
// Opprett en vektor av double. Legg inn fem tall (behøver ikke leses inn.)
// Prøv ut medlemsfunksjonene front() og back(). De returnerer hver et element, og de har ingen
// argumenter.
// Bruk emplace() til å sette inn et tall etter det første elementet. Skriv ut resultatet av front()
// etterpå.
// Prøv ut STL-algoritmen find(). Den tar tre argumenter: start, slutt og søkeverdi. De to første
// er iteratorer til søkeintervallet. Funksjonen returnerer en iterator til den funne verdien, hvis
// den finnes. Hvis den ikke finnes, er returverdien lik end()-iteratoren. (Se f.eks. læreboka kap.
// 16.3.6). Lag et if-uttrykk som sjekker om resultatet av find() er vellykket eller ikke, og
// dersom resultatet var vellykket, skriv ut den funne verdien.
 
 using namespace std;
 
 
 

int main() {

  vector<double> tallene;
  
  tallene.emplace_back(1.3);
  tallene.emplace_back(3.7);
  tallene.emplace_back(1.2);
  tallene.emplace_back(3.4);
  tallene.emplace_back(4.5);
  
  double front = tallene.front();
  double back = tallene.back();
  
  cout << "\nFront: " << front << ", back: " << back << "\n" << endl;
  
  tallene.emplace(tallene.begin()+1,5.6);
  
  cout << "Emplaced 5.6 at position 1, front() is still:  " << tallene.front() << endl;

  auto it = find(tallene.begin(),tallene.end(), 3.4);
  
  if (it != tallene.end()) {
    cout << "\nIn position " << (it - tallene.begin()) << " we found " << *it << "\n" << endl;
  } else {
    cout << "\nDouble not found\n" << endl;
  }
  
}
