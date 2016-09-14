#include <iostream>
#include <string>

using namespace std;

const double moms = 0.25;

class Vare {
  public:
    Vare(const string &varenavn, int, double);
    string finnNavn() const;
    int finnVarenr() const;
    double finnPrisPrEnhet() const;
    double finnPrisUtenMoms(double kvantum);
    double finnPrisMedMoms(double kvantum);
    void settPris(double nyPris);
  
  private:
    string varenavn;
    int varenr;
    double pris;  
};
