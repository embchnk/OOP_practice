/* Zasadniczym celem zadania jest odnalezienie hierarchi klas.
   To znaczy nalezy znalezc "czesc wspolna" pewnych obiektow, ktore wystepuja w temacie.
   W szczegolnosci w rozwiazaniu moga wystapic tylko dwie implementacje funkcji eval. 

   UWAGA: Prosze zwrocic uwage na argumentowosc operacji logicznych.

   UWAGA: Prosze pamietac ze zachowanie polimorficzne wystepuje tylko z & lub *
   
 */

#include <iostream>
#include "Logical.h"

int main() {
  std::cout << "OR   " <<  Logical::eval( OR(), false, false ) << std::endl;
  std::cout << "OR   " <<  Logical::eval( OR(), false, true ) << std::endl;
  std::cout << "AND  " <<  Logical::eval( AND(), false, false ) << std::endl;
  std::cout << "AND  " <<  Logical::eval( AND(), false, true ) << std::endl;
  std::cout << "AND  " <<  Logical::eval( AND(), true, true ) << std::endl;
  std::cout << "XOR  " <<  Logical::eval( XOR(), false, false ) << std::endl;
  std::cout << "XOR  " <<  Logical::eval( XOR(), false, true ) << std::endl;
  std::cout << "XOR  " <<  Logical::eval( XOR(), true, true ) << std::endl;
  std::cout << "NOT  " <<  Logical::eval( NOT(), false ) << std::endl;
  std::cout << "NOOP " <<  Logical::eval( NOOP(), false ) << std::endl; // bez zmian
}
/* wynik
OR   0
OR   1
AND  0
AND  0
AND  1
XOR  0
XOR  1
XOR  0
NOT  1
NOOP 0
 */