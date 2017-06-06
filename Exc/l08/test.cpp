/* 
 * Celem zadania jest napisanie klasy wyj±tków pomocnych przy sprawdzaniu poprawnosci argumentow.
 * Argumenty sa zawsze typu int.
 * 
 * Mozemy sprawdzic czy te argumenty sa: < <=, > >= w stosunku do podanej granicznej wartosc. 
 * W razie gdy limit jest przekroczony funkcje gt, ge, lt, le powinny generowaæ wyj±tek zawierajacy informacje o problemie.
 *
 * Zadanie mozna rozwiazac na dwa sposoby, z jedna klasa badz wieloma klasami wyjatkow. Oba sa dobre.
 * 
 * Nalezy tez napisac przydatny "handler" obslugujacy te wyjatki i dwa uzyteczne makra.
 *
 * UWAGA. Przydatna moze sie okazac funkcja do konkatenacji napisu z liczba. 
 #include <sstream>
 std::string concat(const char* msg, int val) {
  std::ostringstream oss;
  oss << msg << " " << val;
  return oss.str();
}
 */



#include <iostream>
#include "Verifier.h"

void weekDayTest(int x) {
  Verifier::le(7, x);
  Verifier::gt(0, x);

  std::cout << ".. This is day " << x << "\n";
}


void bDayTest(int y, int m, int d) {
  Verifier::ge(1900, y);
  Verifier::lt(2018, y);
  Verifier::ge(0, m);
  Verifier::le(12, m);
  Verifier::ge(1, d);
  Verifier::le(31, d);
  
  std::cout << ".. This is b. day " << y << " " << m << " " << d  << "\n";
}



int main() {

  weekDayTest(3);
  try {
    weekDayTest(0);
  } catch(...) {
    std::cout << ".. Handling arg error\n" ;
    Verifier::handle();
  }

  bDayTest(1980, 12, 1);
  try {
    bDayTest(2013, 34, 12);
    std::cout << ".. We were born in 2013 \n";
  } catch(...) {
    std::cout << ".. Handling arg error\n" ;
    Verifier::handle();
  }
  try {
    throw ArgVerificationFailed(6, "Is incorrect");
  } catch( const ArgVerificationFailed& e ) {
    std::cout << e << std::endl;
  }

  SECURED("test weekday again");
  weekDayTest(99);
  ENDSECURED;
  
}
/*
.. This is day 3
.. Handling arg error
ArgVerificationFailed Argument 0 has to be higher than 0
.. This is b. day 1980 12 1
.. Handling arg error
ArgVerificationFailed Argument 34 has to be lower than or equal 12
Argument 6 Is incorrect
ArgVerificationFailed in test weekday again Argument 99 has to be lower than or equal 7
*/
