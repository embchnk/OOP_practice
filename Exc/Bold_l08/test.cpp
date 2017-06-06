/*
  Celem zadania jest napisanie klasy StatusCode, ktora wspomaga
  programiste w pracy w systemie gdzie nalezy sprawdzac kody bledow. 
  Mianowicie obiekty klasy StatusCode maja dzialc
  w taki sposob:  Podczas konstrukcji pobieraja kod bledu, funkcje
  potwierdzajaca ze kod bledu wskazuje na poprawna wartosc i jakas informacje tekstowa.  
  Jesli na tym obiekcie nigdy nie zostanie wywolana metoda isok() to powinien 
  zostac wyrzucaony wyjatek podczas destrukcji tego obiektu.  
  Wyjatek nie powinien sie pojawic jesli metoda isok() zostala wywolana.
  Cala zabawa pojawia sie przy operatorze kopiujacym zwlaszcza gdy jego argument 
  jest typu const.


  Wyjatek wyrzucony powinien sie nazwyac UncheckedStatusCode 
  i musi przechowac informacje wczesniej zawarta w obiekcie StatusCode.
  
  Do kompletu nalzey napisac  UncheckedStausHandler obslugujacy taki wyjatek 
  i wyjatki standardowe.
 */

#include <iostream>
#include "StatusCode.h"


using namespace std;
int main() {
  try {
    {
      StatusCode sc = StatusCode::ALLOK();  // wywolanie bezproblemowe
      if ( sc.isok() )
      cout << "ok " << endl;
      else
	cout << "not ok " << sc.info() << endl;
    }
    {
      StatusCode sc = StatusCode::ERROR("Blad");
      if ( sc.isok() )
	cout << "ok " << endl;
      else
	cout << "not ok " << sc.info() << endl;
    }
    {
      const StatusCode sc = StatusCode::ALLOK();
      StatusCode sc2  = sc; // tu sc2 przejmuje funkcje sprawdzenia czy byl sprawdzony
      sc2.isok();
      std::cout << "Kod bledu sprawdzony, nie ma wyjatku.\n";
    }
    {
      {
	StatusCode sc = StatusCode::ALLOK();
      }
      std::cout << "Nie sprawdzamy kodu bledu\n";
    }
  } catch (...) {
    UncheckedStausHandler::handle();
  }

  try {
    throw std::runtime_error("jakis blad");
  } catch(...) {
    UncheckedStausHandler::handle();
  }     
}
/* wynik
ok 
not ok Blad
Kod bledu sprawdzony, nie ma wyjatku.
..Handling UncheckedStatusCode 
..Handling std::exception jakis blad
 */
