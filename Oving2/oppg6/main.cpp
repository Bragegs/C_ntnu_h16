#include <iostream>
using namespace std;

int finnSum(const int *tabell, int antElementer){
  int sum = 0;
  for (int teller = 0; teller < antElementer ; teller++) {
    sum += tabell[teller];
  }
  return sum;
}
int main() {
  const int antallElementer = 20;
  int tabell[20];
  
  for(int i=0; i<antallElementer;i++){
    tabell[i] = (i+1);
  }
  
  cout << "Summen av de 10(1-10) første tallene = " << finnSum(tabell, 10) << endl;
  cout << "Summen av de 5(11-15) neste tallene = " << finnSum(&tabell[10], 5) << endl;
  cout << "Summen av de 5(16-20) siste tallene = " << finnSum(&tabell[15], 5) << endl;
}
