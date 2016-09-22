#include <iostream>
#include <vector>

using namespace std;
 
int main() {

  vector<double> tallene;
  
  tallene.emplace_back(1.3);
  tallene.emplace_back(3.7);
  tallene.emplace_back(1.2);
  tallene.emplace_back(3.4);
  tallene.emplace_back(4.5);
  
  double front = tallene.front();
  double back = tallene.back();
  
  cout << "\nFront: " << front << ", back: " << back << "\n" << endl;
  
  tallene.emplace(tallene.begin()+1,5.6);
  
  cout << "Emplaced 5.6 at position 1, front() is still:  " << tallene.front() << endl;

  auto it = find(tallene.begin(),tallene.end(), 3.4);
  
  if (it != tallene.end()) {
    cout << "\nIn position " << (it - tallene.begin()) << " we found " << *it << "\n" << endl;
  } else {
    cout << "\nDouble not found\n" << endl;
  }
  
}
