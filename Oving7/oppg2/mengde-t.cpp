#include "mengde.h"
#include <iostream>
#include <string>

using namespace std;



int main() {
  Mengde a(vector<int>{1,2,3});
  Mengde b(vector<int>{4,5,6,7,8});
  Mengde c = Mengde();
  a.skrivUt();
  b.skrivUt();
  c.skrivUt();
  
  a += 4;
  a.skrivUt();
  a += 4;
  a.skrivUt();
  a = a + 4;
  a.skrivUt();
  a = 10 + a;
  a.skrivUt();
  a = b;
  a.skrivUt();
  a = b+9;
  a.skrivUt();
}