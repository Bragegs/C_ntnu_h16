#include "broek.h"
#include <iostream>
#include <string>

using namespace std;

void skriv(const string &tekst, const Broek &Broek);

int main() {
  Broek a(10, 20);
  Broek b(3, 4);
  Broek c;
  c.settBroek(5);
  Broek d = a / b;

  skriv("a = ", a);
  skriv("b = ", b);
  skriv("c = ", c);
  skriv("d = ", d);

  b += a;
  ++c;
  d *= d;

  skriv("b = ", b);
  skriv("c = ", c);
  skriv("d = ", d);

  c = a + b - d * a;
  c = -c;

  skriv("c = ", c);

  if (a + b != c + d)
    cout << "a + b != c + d" << endl;
  else
    cout << " a + b == c + d" << endl;
  while (b > a)
    b -= a;
  skriv("b = ", b);
  
  
  cout << "oppg 1a:\n" << endl;
  
  cout << "Første argumentet er Broek" << endl;
  skriv(" ( 10 / 20 ) - 5 = ",a-5);
  
  cout << "\nFørste argumentet er ikke Broek" << endl;
  skriv(" 5 - ( 10 / 20 ) = ",5-a);
  
  cout << "oppg 1B:\n" << endl;
  skriv("5 - 3 - ( 10 / 20) - 7 - ( 1 / 4 ) = ",5-3-a-7-b);
  
  cout << "\nSteg 1:  2 - ( 10 / 20) operator der første argument ikke er Broek" << endl;
  cout << "Steg 2:  ( 3 / 2 ) - 7 operator der første argument er Broek" << endl;
  cout << "Steg 3:  ( -11 / 2 ) - ( 1 / 4 ) broek - broek(Broek operator-(const Broek &denAndre) const)" << endl;
  return 0;
}

void skriv(const string &tekst, const Broek &broek) {
  cout << tekst << broek.finnTeller() << " / ";
  cout << broek.finnNevner() << endl;
}
