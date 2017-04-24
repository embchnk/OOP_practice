// Nazwa pliku wykonywalnego: Wyjatki

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// UWAGA!
// Nie wolno korzystać ze zmiennych i funkcji statycznych, ani ze
// zmiennych globalnych.

// Prosze zaimplementowac klase ObiektMiotajacy i klasy typ od 1 do
// 4. ObiektMiotajacy musi miec zaimplementowana metoda Rzuc(),
// natomiast klasy typ1 do typ4 metode PrzedstawSie(), ktora wypisuje
// na ekranie z jakiego typu obiektem mamy do czynienia.

// Funkcja Przetworz1 i instrukcje w blokach catch(typ3*) i
// catch(typ4*) wypisuja na ekran adres przechowywany we wskazniku
// wyjatek.

// Prosze zwrocic uwage na zarzadzanie pamiecia. Bardzo wazne jest aby
// nie bylo zadnych wyciekow pamieci.

// Pliku Main.cpp, nie wolno modyfikowac.

// Komentarz w kodzie mowia jakie wyjscie powinna generowac dana
// linia.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod). 

// Program nalezy kompilowac z flagami -Wall -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow (w tym wlasnych wczesniej
// przygotowanych plikow oprocz makefile)

// Rozwiazanie (czyli dodane pliki, makefile i Main.cpp) nalezy
// wgrac do UPEL.




#include"Main.h"
#include<iostream>

void Funkcja ()
{
  try {
    ObiektMiotajacy* miotacz = new ObiektMiotajacy;
    miotacz->Rzuc();
    std::cout<<"Ukryty przekaz"<<std::endl;
  }
  catch (typ1* wyjatek)
    {
      Przetworz1 (wyjatek);	// Przetworz1 - wyjatek typu 1 o adresie: ....
    }
  catch (typ2* wyjatek)
    {
      Przetworz1 (wyjatek); 	// Przetworz1 - wyjatek typu 2 o adresie: ....
    }
}


int main ()
{
  using namespace std;
  
  cout<<"Wprowadzenie\n";
  typ1 a; a.PrzedstawSie();	// Nazywam sie 1
  typ2 b; b.PrzedstawSie();	// Nazywam sie 2
  typ3 c; c.PrzedstawSie();	// Nazywam sie 3
  typ4 d; d.PrzedstawSie();	// Nazywam sie 4
  cout<<"Koniec wprowadzenia\n";

  
  try {
    Funkcja();
    cout<<"Ukryty przekaz"<<endl;
  }
  catch (typ3* wyjatek) {
    cout<<"Zlapalem wyjatek typu 3 w linii "<<__LINE__<<". Adres wyjatku: "<<wyjatek<<endl;
    delete wyjatek;
  }
  catch (typ4* wyjatek) {
    cout<<"Zlapalem wyjatek typu 4 w linii "<<__LINE__<<". Adres wyjatku: "<<wyjatek<<endl;
    delete wyjatek;
  }

  return 0;
}
/*
Wprowadzenie
Nazywam sie 1
Nazywam sie 2
Nazywam sie 3
Nazywam sie 4
Koniec wprowadzenia
Przetworz1 - wyjatek typu 2 o adresie: <adres>
Zlapalem wyjatek typu 4 w linii 86. Adres wyjatku: <ten_sam_adres>
*/
