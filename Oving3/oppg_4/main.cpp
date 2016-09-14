#include <iostream>
#include <cstring> 

using namespace std;

int main() {

  cout << "a) \n" << endl;
  
  string ord1 = "";
  string ord2 = "";
  string ord3 = "";
  
  cout << "skriv inn ord1:" << endl;
  cin >> ord1;
  cout << "skriv inn ord2:" << endl;
  cin >> ord2;
  cout << "skriv inn ord3:" << endl;
  cin >> ord3;

  
  cout << "\n b) \n" << endl;
   
   string setning = ord1 + " " + ord2 + " " + ord3 + ".";
   cout << setning << endl;
 
  cout << "\n c) \n" << endl;
     
   cout << "Variabel    " << "Lengde: " << endl;
   cout << "ord1:       " << ord1.size() << endl;
   cout << "ord2:       " << ord2.size() << endl;
   cout << "ord3:       " << ord3.size() << endl;
   cout << "setning:    " << setning.size() << endl;
     
  cout << "\n d) \n" << endl;
     
   string setning2 = setning;
   cout << "kopiert" << endl;
   
  cout << "\n e) \n" << endl;
   
   for(unsigned int i=0; i < setning2.length();++i) {
      if (i >= 9 && i <= 11) {
        setning2.replace(i,1,"x");
        if (i == 11) {
          break;
        }
      }
   }
   
   cout << "setning2: " << setning2 << endl;
   
  cout << "\n f) \n" << endl;
   
   string begynnelsen = "";
   for(unsigned int i=0; i < setning.length();++i) {
      if (i < 5) {
        begynnelsen += setning[i];
        if (i==4) {
          break;
        }
      }
   }
   
   cout << "begynnelsen: " << begynnelsen << endl;
   
  cout << "\n g) \n" << endl;
   
   if (setning.find("hallo") != string::npos) {
     cout << "Setning inneholder strengen hallo" << endl;
   }else{
     cout << "Setning inneholder ikke strengen hallo" << endl;
   }
   
  cout << "\n h) \n" << endl;
   
   int antFunnetEr = 0;
   size_t plass = setning.find("er");
   
   while (plass != string::npos) {
     cout << "Fant 'er' i posisjon " << plass+1 << endl;
     antFunnetEr++;
     plass = setning.find("er", plass+1);
   }
   cout << "Antall er'er i setning er: " << antFunnetEr << endl;
}
