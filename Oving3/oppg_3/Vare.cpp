#include <string>
#include <string>
#include "Vare.h"

using namespace std;

Vare::Vare (const string &varenavn, int varenr, double pris) :
  varenavn(varenavn), varenr(varenr), pris(pris){}

string Vare::finnNavn() const {
  return varenavn;
}

int Vare::finnVarenr() const {
  return varenr;
}

double Vare::finnPrisPrEnhet() const {
  return pris;
}

double Vare::finnPrisUtenMoms(double kvantum) {
  return pris * kvantum;
}

double Vare::finnPrisMedMoms(double kvantum) {
  return (pris*kvantum)*(1+moms);
}

void Vare::settPris(double nyPris){
  pris = nyPris;
}