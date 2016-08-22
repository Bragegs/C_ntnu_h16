#include <iostream>

int main() {
  
  const int antall = 5;
  int antall_u_10 = 0;
  int antall_m_10_20 = 0;
  int antall_o_20 = 0;
  int temp;
  
  for(int i = 0; i < antall; i++){
    std::cout << "Temperatur for dag " << (i+1) << ": " << std::endl;
    std::cin >> temp;
   // std::cout << temp << std::endl;
    
    if (temp < 10) {
      antall_u_10++;
    } else if (temp >= 10 && temp <= 20) {
      antall_m_10_20++;
    } else {
      antall_o_20++;
    }
    
    if ( (i+1) == antall ) {
      std::cout << "Antall under 10: " << antall_u_10 << std::endl << "Antall mellom 10 og 20: " << antall_m_10_20 << std::endl << "Antallet over 20: " << antall_o_20 << std::endl;
    }
  }
  
}