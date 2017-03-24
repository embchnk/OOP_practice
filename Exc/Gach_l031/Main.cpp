// Nazwa pliku wykonywalnego: Tablica

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze napisac klase reprezentujaca tablice liczb
// calkowitych. Pamiec powinna byc alokowana dynamicznie i rozmiar
// tablicy zawsze powinien byc dopasowany do jej zawartosci.

// UWAGA!
// Do rozwiazania zadania nie wolno wykorzystac zadnych elementow
// biblioteki standardowej oprocz cout i endl.

// Prosze zaimplemntowac tylko te operatory i funkcje, ktore sa
// wykorzystywane w funkcji main i ktore trzeba
// zaimplementowac. Implementacja zupelnie zbednych funkcji lub
// operatorow bedzie obnizala ocene.

// Pliku Main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod). 

// Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie Tablica. Program nalezy kompilowac z flagami -Wall -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow (w tym wlasnych wczesniej
// przygotowanych plikow oprocz makefile)

// Rozwiazanie (czyli dodane pliki, makefile i Main.cpp) nalezy
// wgrac do UPEL.

#include"Main.h"
#include<iostream>

int main ()
{
  using namespace std;

  int surowaTablica [] = {2, 4, 6};
  const Tablica* const pierwsza = new Tablica (surowaTablica, sizeof(surowaTablica)/sizeof(int));
  cout<<"Pierwsza: "<<*pierwsza<<"\n"; // Pierwsza: 2, 4, 6

  Tablica* druga = new Tablica;
  Tablica& trzecia = *druga;

  *druga = *pierwsza + 2 + 3 + 5;
  cout<<"Druga: "<<*druga<<"   Pierwsza: "<<*pierwsza<<"\n"; // Druga: 2, 4, 6, 2, 3, 5   Pierwsza: 2, 4, 6

  *druga + 4 + 6;
  cout<<"Druga II: "<<*druga<<"\n"; // Druga II: 2, 4, 6, 2, 3, 5

  trzecia = *druga;
  cout<<"Trzecia: "<<trzecia<<"\n"; // Trzecia: 2, 4, 6, 2, 3, 5

  trzecia(0) = trzecia(1);
  trzecia(1) = 2;
  cout<<"trzecia II: "<<trzecia<<"   Pierwsza: "<<(*pierwsza)(0)<<", "<<(*pierwsza)(1)<<"\n"; // trzecia II: 4, 2, 6, 2, 3, 5   Pierwsza: 2, 4

  cout<<"Bez szostki "<< *druga - 6 <<"\n"; // Bez szostki 4, 2, 2, 3, 5

  cout<<"Bez dwojek "<< (*druga -= 2) <<"\n"; // Bez dwojek 4, 6, 3, 5

  trzecia = *pierwsza + *druga;

  for (Tablica::IteratorStaly liczba = pierwsza->poczatek(); liczba != pierwsza->koniec(); ++liczba)
    cout <<*liczba<<", ";
  cout<<*pierwsza->koniec()<<"\n";

  Tablica niepowtarzalna = trzecia.tylkoPierwszeWystapienia();
  cout<<"Trzecia III: "<<trzecia<<"\n"; // Trzecia III: 2, 4, 6, 4, 6, 3, 5
  cout<<"Niepowtarzalna: "<< niepowtarzalna<<"\n"; // Niepowtarzalna: 2, 4, 6, 3, 5

  for (Tablica::Iterator liczba = druga->poczatek(); liczba != druga->koniec(); ++liczba)
    *liczba = 0;
  *druga->koniec()=0;

  cout<<"Wyzerowana: "<<*druga<<"\n"; // Wyzerowana: 0, 0, 0, 0, 0, 0, 0
  
  delete pierwsza;
  delete druga;

  return 0;
}
/*
Pierwsza: 2, 4, 6
Druga: 2, 4, 6, 2, 3, 5   Pierwsza: 2, 4, 6
Druga II: 2, 4, 6, 2, 3, 5
Trzecia: 2, 4, 6, 2, 3, 5
trzecia II: 4, 2, 6, 2, 3, 5   Pierwsza: 2, 4
Bez szostki 4, 2, 2, 3, 5
Bez dwojek 4, 6, 3, 5
2, 4, 6
Trzecia III: 2, 4, 6, 4, 6, 3, 5
Niepowtarzalna: 2, 4, 6, 3, 5
Wyzerowana: 0, 0, 0, 0, 0, 0, 0
*/
