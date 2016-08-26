#include <iostream>
using namespace std;

int main() {
  double tall;
  
  double *peker = &tall;
  double &ref = tall;
  
  ref = 1;
  cout << "Tilordnet verdi med ref = " << tall << endl;
  
  *peker = 2;
  cout << "Tilordnet verdi med peker = " << tall << endl;
  
  tall = 3;
  cout << "Tilordnet verdi med tall = " << tall << endl;
}
