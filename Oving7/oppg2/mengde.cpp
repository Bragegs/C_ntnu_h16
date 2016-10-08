#include "mengde.h"
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
Mengde::Mengde(){
  tomMengde();
}
Mengde::Mengde(const vector<int> vektor) : mengden(vektor) {}

void Mengde::tomMengde(){
  mengden = vector<int>();
}

void Mengde::skrivUt(){
    cout << "{";
    
    for(auto &tall : mengden){
      cout << tall;
      if(tall != mengden.back()){
        cout << ", ";
      }
    }
    
    cout << "}\n";
}

Mengde Mengde::operator+(const Mengde &denAndre) const {
  Mengde hjelp = *this;
  hjelp += denAndre;
  return hjelp;
}

Mengde Mengde::operator+(int tall) const{
  vector<int> vektor = {tall};
  Mengde hjelp(vektor);
  hjelp += *this;
  return hjelp;
}

Mengde operator+(int tall, const Mengde &denAndre){
  Mengde hjelp;
  hjelp = denAndre + tall;
  return hjelp;
}

Mengde &Mengde::operator=(const Mengde &original){
  mengden = original.mengden;
  return *this;
}

Mengde &Mengde::operator+=(const Mengde &denAndre){
  for(auto &tall : denAndre.mengden){
    if(!mengdenContains(tall)) mengden.emplace_back(tall);
  }
  return *this;
}

Mengde &Mengde::operator+=(int tall){
  if(!mengdenContains(tall)) mengden.emplace_back(tall);
  return *this;
}

bool Mengde::mengdenContains(int tall){
  if(find(mengden.begin(), mengden.end(), tall) != mengden.end()){
    return true;
  }
  return false;
}
