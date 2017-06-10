/* Z uzyciem kont. standarodowych prosze napisac pozyteczny szablon licznik.
   Funkcjonalnosc jak w przykladzie.
 */

#include <iostream>
#include "Licznik.h"


int main() {
  using namespace std;
  typedef Licznik<char> CharLicz;
  CharLicz l;

  const char* n = "Ala maaaa kotaaaaa, ktory mrrrruczy";

  l.dodaj(n, n+strlen(n));
  l.dodaj('q');

  cout << l.ilosc('a') << endl; 
  cout << l.ilosc('r') << endl;
  cout << l.ilosc('q') << endl; 
  l.statystyka(cout);
  
  const std::vector<char>v( l.najczestsze(2) );
  pvec(v, cout);

  typedef Licznik<std::string> StrLicz;
  StrLicz wc;
  wc << "ala" << "ma" << "kota" << "ma" << "ala" << "kota" << "ma" << "re" << "ra" << "ro";
  wc.statystyka(cout);

  
  const std::vector<StrLicz::value_type> r = wc.najczestsze(3);
  
  pvec(r, cout);
}
/* wynik
10
5
1
  - 4
, - 1
A - 1
a - 10
c - 1
k - 2
l - 1
m - 2
o - 2
q - 1
r - 5
t - 2
u - 1
y - 2
z - 1

a r 
ala - 2
kota - 2
ma - 3
ra - 1
re - 1
ro - 1

ma ala kota 

 */
