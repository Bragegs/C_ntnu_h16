#include <iostream>
#include <fstream>
using namespace std;

void lesInnTemp(double temp[], int antall) {
  ifstream tekstFil("temperaturer.txt");
  string linje;
   if (tekstFil.is_open()) {
     cout << "Leser fra fil..." << endl;
     for(int i=0; i<antall; i++) {
       if (getline(tekstFil, linje)) {
         temp[i] = stod(linje);
       }
     }
     tekstFil.close();
     cout << "Lukker fil" << endl;
   } else {
     cout << "kunne ikke åpne fil";
   }
}

void skrivResultat(double temp[], int antall) { 
  int antall_u_10 = 0;
  int antall_m_10_20 = 0;
  int antall_o_20 = 0;
  
  for(int i = 0; i < antall; i++){
    double temperatur = temp[i];
    cout << "Temperatur for dag " << (i+1) << ": " << temperatur << endl;

    if (temperatur < 10) {
      antall_u_10++;
    } else if (temperatur >= 10 && temperatur <= 20) {
      antall_m_10_20++;
    } else {
      antall_o_20++;
    }
    
  }
  cout << "Antall under 10: " << antall_u_10 << endl << "Antall mellom 10 og 20: " << antall_m_10_20 << endl << "Antallet over 20: " << antall_o_20 << endl;
}

int main() {
  const int antall = 5;
  double temp[5];
  
  lesInnTemp(temp, antall);
  skrivResultat(temp, antall);
}
