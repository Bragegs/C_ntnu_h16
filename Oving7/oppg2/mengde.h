#ifndef MENGDE_DEFINERT
#define MENGDE_DEFINERT

#include <vector>
using namespace std;

class Mengde {
public:
  Mengde();
  Mengde(const vector<int> vektor);
  void tomMengde();
  void skrivUt();
  Mengde operator+(const Mengde &denAndre) const;
  Mengde operator+(int tall) const;
  Mengde &operator+=(const Mengde &denAndre);
  Mengde &operator+=(int tall);
  Mengde &operator=(const Mengde &original);          

private:
  vector<int> mengden;
  bool mengdenContains(int tall);
};

Mengde operator+(int tall, const Mengde &denAndre);

#endif