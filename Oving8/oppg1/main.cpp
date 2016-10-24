#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
template <class type>
bool likhet(type &a, type &b){
  bool test = (a == b);
  cout << "templatefunksjon returns " << test << endl;
  return test;
}

bool likhet(double &a, double &b){
  double minst = 0.00001;
  double forskjell = fabs(a-b);
  bool test = forskjell < minst;
  cout << "dobulefunksjon returns " << test << endl;
  cout << fixed << showpoint << "forskjellen var: "<< setprecision(6) << forskjell << endl;
  return test;
}

int main() {
  int a = 2;
  int b = 2;
  int c = 3;
  

  cout << "Tester likhet med a=2 og b = 2:  " << endl;
  likhet(a,b);
  cout << "Tester likhet med a=2 og c = 3: "<< endl;
  likhet(a,c);
  
  double d = 2.00002;
  double e = 2.000011;
  double f = 2.00000;
  
  cout << "Tester likhet med d=2.00002 og e = 2.00001:  " << endl;
  likhet(d,e);
  cout << "Tester likhet med d=2.00002 og f = 2.00000:  " << endl;
  likhet(d,f);
}
