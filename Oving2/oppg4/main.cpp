#include <iostream>

int main() {
 /* int a = 5;
  int &b; //  prøve å lage en referanse uten fortelle hvilken variabel den referer til
  int *c; // Pekere skal initieres med nullptr eller en verdi
  c = &b;
  &a = *b + *c; // Peker-dereferanse til en int
  &b = 2; // prøve å lage en referanse uten fortelle hvilken variabel den referer til
  */
  int a = 5;
  int b = 2; 
  int *c = &b;
  a = *c + *c;

}
