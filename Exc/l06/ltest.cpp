/* Zasadniczym celem zadania jest odnalezienie hierarchi klas.
   To znaczy nalezy znalezc "czesc wspolna" pewnych obiektow, ktore wystepuja w temacie.

   UWAGA: Od poczatku prosze zadbac o poprawnosc const
 */

#include <iostream>
#include "Opcje.h"

int main() {

  // to sie ma nie kompilowac
  // new Opcja("y")
  
  {
    Opcja *o = new OpcjaArgumentowa("s", "45");    
    std::cout << o->str() << std::endl; // mozna uzyc klasy string
    delete o;
  }

  {
    OpcjaArgumentowa *o = new OpcjaArgumentowa("s", "45");    
    std::cout << o->arg() << std::endl; // mozna uzyc klasy string
    delete o;
  }

  {
    Opcja *o = Op::Bezargumentowa("x");
    std::cout << o->str() << std::endl; // mozna uzyc klasy string
    delete o;    
  }

  Opcja* o1  = Op::dekoduj("-d");
  Opcja* o2  = Op::dekoduj("-r 5");
  Opcja* o3  = Op::dekoduj("-lista");
  
  std::cout << o1->typ() << " " << o1->nazwa() << " " << o1->str() << std::endl;
  std::cout << o2->typ() << " " << o2->nazwa() << " " << o2->str() << std::endl;
  std::cout << o3->typ() << " " << o3->nazwa() << " " << ((const Opcja*)o3)->str() << std::endl;

  delete o1;
  delete o2;
  delete o3;

}
/* wynik
-s 45
45
-x
OpcjaBezArgumentowa d -d
OpcjaArgumentowa r  -r  5
OpcjaBezArgumentowa lista -lista
 */
