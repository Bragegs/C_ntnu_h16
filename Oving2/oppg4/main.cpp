#include <iostream>

int main() {
 /* int a = 5;
  int &b; //  prøve å lage en referanse uten fortelle hvilken variabel den referer til
  int *c; // Pekere skal initieres med nullptr eller en verdi
  c = &b; // b må vell være initialisert først?
  &a = *b + *c; // Peker-dereferanse til en int
  &b = 2; // prøve å lage en referanse uten fortelle hvilken variabel den referer til
  ^ Kan vell ikke endre en adresse slik?
  */
    
    
  //Oppgaven noe diffus, lagde et kjørende program.  
    int a = 5;
    int& b = a; //sier at b skal ha samme minnelokasjon som a
    int *c; // Burde initialiseres men ikke nødvendig
    c = &b; // sier at c skal peke til minnelokasjonen til b
    a = b + *c; // denne er unødvendig når vi endrer b under men gir a verdien 10
    b = 2; // Kunne lige godt stå a = 2 på grunn av samme minnelokasjon

}
