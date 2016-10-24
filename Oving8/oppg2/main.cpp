#include <iostream>

using namespace std;

template <class type1, class type2>
class Par {
public:
  type1 forste;
  type2 andre;
  
  Par(type1 forste, type2 andre) : forste(forste), andre(andre) {}

  Par operator+(const Par &denAndre) {
    Par par = *this;
    par.forste += denAndre.forste;
    par.andre += denAndre.andre;    
    return par;
  }

  bool operator>(const Par &denAndre) const {
    type1 sumforste = this->forste+this->andre;
    type1 sumandre = denAndre.forste + denAndre.andre;
    return (sumforste > sumandre);
  }
};


int main() {

//forutsetter at + operatorer eksisterer for int og double i dette tilfellet
//forutsetter at > operatorer eksisterer for int og double i dette tilfellet
  Par<double, int> p1(3.5, 14);
  Par<double, int> p2(2.1, 7);
  cout << "p1: " << p1.forste << ", " << p1.andre << endl;
  cout << "p2: " << p2.forste << ", " << p2.andre << endl;
  if (p1 > p2)
  cout << "p1 er størst" << endl;
  else
  cout << "p2 er størst" << endl;
  auto sum = p1 + p2;
  cout << "Sum: " << sum.forste << ", " << sum.andre << endl;
}
