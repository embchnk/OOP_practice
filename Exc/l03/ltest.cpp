/*
  Celem zadania jest napisanie kontenera specjalnego przeznaczenia. 
  Kontener ten ma dzialac tak aby optymalne bylo wstawienie na poczatku i na koncu a takze dostep z uzyciem operatora []. 
  
  Implementacja ma sie skladac z dwoch tablic, 
  jeden obslugujace operacje dodawania na koncu a drugi operacje
  dodawania do poczatku.
  nowy el -> LLLLLLPPPPPP <- nowy el
  Mozna w klasie BiVector prealokowac dwie wieksze tablice na czesc "przedia i tylna".

  
  Kompilowac z -Wall -g
 */

#include <iostream>
#include "BiVector.h"


int main() {
  BiVector a;
  a.push_back(1);
  a.push_back(2);
  a.push_back(3);
  std::cout << a[0] << " " << a[1] << " " << a[2] << std::endl;

  a.push_front(5);
  a.push_front(6);
  a.push_front(7);
  std::cout << a[0] << " " << a[1]  << " " << a[2] << " " << a[3]  << " " << a[4] << std::endl;

  BiVector b;
  b.push_back(1).push_back(0).push_back(7);
  b.push_front(101).push_front(100);
    
  for ( BiVector::const_iterator i = b.begin(); i != b.end(); ++i )
    std::cout << *i << " ";
  std::cout << std::endl;	

}
/* wynik
1 2 3
7 6 5 1 2
100 101 1 0 7 
 */
