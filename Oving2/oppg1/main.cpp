#include <iostream>
using namespace std;

int main() {
  
  int i = 3;
  int j = 5;
  int *p = &i;
  int *q = &j;
  
  cout << "Variabel:    Adresse(16-tallsystem):    Innhold:" << endl;
  cout << endl;
  cout << "    i            " <<  &i << "       " << "     " << i << endl;
  cout << "    j            " <<  &j << "       " << "     " << j << endl;
  cout << "    *p           " <<  &*p << "       " << "     " << *p << endl;
  cout << "    *q           " <<  &*q << "       " << "     " << *q << endl;
  
  *p = 7;
  *q += 4;
  *q = *p + 1;
  p = q;
  
  cout << "Variabel:    Adresse(16-tallsystem):    Innhold:" << endl;
  cout << endl;
  cout << "    i            " <<  &i << "       " << "     " << i << endl;
  cout << "    j            " <<  &j << "       " << "     " << j << endl;
  cout << "    *p           " <<  &*p << "       " << "     " << *p << endl;
  cout << "    *q           " <<  &*q << "       " << "     " << *q << endl;
  
}
