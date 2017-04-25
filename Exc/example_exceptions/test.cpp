/* 
   Celem zadania jest napisanie pomocniczej klasy DoUndo, ktora pozwala 
   na odwolanie operacji w wypadku wyrzucenia wyjatku.

   Jak to jest robione powinno byc ewidentne po przeczytaniu zawartosci klasy Msg.

   UWAGA: Prosze zauwazyc ze w trFail ostania funkcja statyczna
   DoUndo::allok() nie jest wywolywana, jest to f. statyczna!  

   UWAGA: KeepInt musi przechowac zarowno wartosc poczatkow ja i
   referencje do miejsca gdzie mozna odlozyc te wartosc jeslu undo jest wolane.
   
   Prosze na przyszlosc przemyslec jak zamienic program, w ktorym obsluge bledow wykonuje sie przez zwracanie kodu bledu
   na program, w ktorym do tego sa uzywane wyjatki tak aby ilosc zmian w kodzie byla minimalna (zadna).
   np. jesli w kodzie mamy:
   return OK; // wykonanie porawne
   return FAIL; // wykonanie niepoprawne 

 */
#include <iostream>
#include <stdexcept>
#include "DoUndo.h"


class Msg : public DoUndoAction {
  void dodo() {
    std::cout << "Entering transaction" << std::endl;
  }    
  void undoOk() {
    std::cout << "Finished transaction" << std::endl;
  }
  void undoFail() {
    std::cout << "Broken transaction" << std::endl;
  }
  
};

int konto1 = 100;
int konto2 = 20;

void trOK() {
  DoUndo msg(new Msg());
  const int wartosc = 10;
  DoUndo k1(new KeepInt(konto1));
  DoUndo k2(new KeepInt(konto2));
  konto1 -= wartosc;
  konto2 += wartosc;
  DoUndo::allok();

  
}


void trFail() {
  DoUndo msg(new Msg());
  const int wartosc = 14;
  DoUndo k1(new KeepInt(konto1));
  DoUndo k2(new KeepInt(konto2));
  konto1 -= wartosc;
  throw std::runtime_error("Tranzakcja przerwana z nieznanej przyczyny");
  DoUndo::allok();
}


int main() {
  try {
    trOK();
    std::cout  << "konto1 " << konto1 << " konto2 " << konto2 << std::endl;
    trFail();
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
    std::cout  << "konto1 " << konto1 << " konto2 " << konto2 << std::endl;
  }
  
}
/* wynik
./exc  | tee results
Entering transaction
Finished transaction
konto1 90 konto2 30
Entering transaction
Broken transaction
Tranzakcja przerwana z nieznanej przyczyny
konto1 90 konto2 30

 */
