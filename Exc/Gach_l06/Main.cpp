// Nazwa pliku wykonywalnego: Mechaniczne

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// UWAGA!!!
// Kazda z linii znajdujaca sie w blokach BLAD powinna powodowac blad
// kompilacji. Za kazda linie, ktora niepowoduje bledu kompilacji
// ocena za zadanie jest zmniejszana o 1 punkt.

// Prosze dopisac klasy potrzebne do poprawnego dzialania programu

// Klasa Nazwany jest juz zaimplementowana i jej implementacji nie
// wolno zmieniac i obowiazkowo trzeba uzyc tej implementacji do
// rozwiazania zadania.

// Klasy Samochod, Rower, PilaSpalinowa i Srubokret sa czesciowo
// zaimplementowane. W ich kodzie mozna wszystko zmieniac. Jezeli
// bedzie Panstwu to mozna napisac caly kod tych klas od poczatku
// samodzielnie. Nie trzeba korzystac z przygotwanych
// fragmentow.

// W zadaniu mozna korzystac z elementow bilbioteki standardowej
// zwlaszcza klasy std::string, ktora jest dostepna w pliku o nazwie
// "string".

// Plikow Main.cpp i Nazwany.h, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod). 

// Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie RuchomeObrazki. Program nalezy kompilowac z flagami -Wall -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow (w tym wlasnych wczesniej
// przygotowanych plikow oprocz makefile)

// Rozwiazanie (czyli dodane pliki, makefile i Main.cpp) nalezy
// wgrac do UPEL w postaci archiwum spakowanego tarem przy uzyciu polecenia:
// tar czf lab6.tar.gz *

#include<iostream>
#include<string>

#include"Main.h"

// #define BLAD_PIERWSZY
// #define BLAD_DRUGI
// #define BLAD_TRZECI
// #define BLAD_CZWARTY

int main ()
{
  const std::string nazwa = "moje porsche";
  const float predkoscMaxPorsche = 286;
  const float poziomOlejuPorsche = 0.96;
  Samochod porsche(nazwa, predkoscMaxPorsche, poziomOlejuPorsche);

#ifdef BLAD_PIERWSZY
  porsche.WypiszZastosowanie();
  porsche.WypiszZrodloNapedu();
#endif

  const float predkoscMaxRower = 42;
  const std::string zrodloNapeduRoweru = "nog";
  Rower romet ("wigry3", predkoscMaxRower, zrodloNapeduRoweru);
#ifdef BLAD_DRUGI
  romet.WypiszZastosowanie();
  romet.WypiszPoziomOleju();
#endif

  const std::string  zastosowaniePily = "ciecia";
  const float poziomOlejuPily = 0.65;
  PilaSpalinowa pila ("husqvarna", zastosowaniePily, poziomOlejuPily);

#ifdef BLAD_TRZECI
  pila.WypiszPredkoscMaksymalna();
  pila.WypiszZrodloNapedu();
#endif

  const std::string  zastosowanieWkretaka = "wkrecania";
  const std::string zrodloNapeduWkretaka = "reki";
  Srubokret wkretak ("krzyzak", zastosowanieWkretaka, zrodloNapeduWkretaka);
#ifdef BLAD_CZWARTY
  wkretak.WypiszPredkoscMaksymalna();
  wkretak.WypiszPoziomOleju();
#endif

  const Pojazd* tablicaPojazdow [] = {&porsche, &romet};
  const Narzedzie* tablicaNarzedzi [] = {&pila, &wkretak};
  const Spalinowy* tablicaSpalinowych [] = {&porsche, &pila};
  const Reczny* tablicaRecznych [] = {&romet, &wkretak};
  
  const Nazwany* tablicaNazwanych [] = {&porsche, &wkretak, &romet, &pila};

  std::cout<<"===== POJAZDY =====\n";
  for (unsigned int indeks = 0; indeks < sizeof(tablicaPojazdow)/sizeof(Pojazd*); indeks++)
    tablicaPojazdow[indeks]->WypiszPredkoscMaksymalna();

  std::cout<<"\n";
  std::cout<<"===== NARZEDZIA =====\n";
  for (unsigned int indeks = 0; indeks < sizeof(tablicaNarzedzi)/sizeof(Narzedzie*); indeks++)
    tablicaNarzedzi[indeks]->WypiszZastosowanie();

  std::cout<<"\n";
  std::cout<<"===== SPALINOWE =====\n";
  for (unsigned int indeks = 0; indeks < sizeof(tablicaSpalinowych)/sizeof(Spalinowy*); indeks++)
    tablicaSpalinowych[indeks]->WypiszPoziomOleju();
  
  std::cout<<"\n";
  std::cout<<"===== RECZNE =====\n";
  for (unsigned int indeks = 0; indeks < sizeof(tablicaRecznych)/sizeof(Reczny*); indeks++)
    tablicaRecznych[indeks]->WypiszZrodloNapedu();

  std::cout<<"\n";
  std::cout<<"===== NAZWANE =====\n";
  for (unsigned int indeks = 0; indeks < sizeof(tablicaNazwanych)/sizeof(Nazwany*); indeks++) {
    tablicaNazwanych[indeks]->Wypisz();
    std::cout<<"\n";
  }

  return 0;
}
/*
===== POJAZDY =====
Predkosc maksymalna tego pojazdu wynosi 286 km/h.
Predkosc maksymalna tego pojazdu wynosi 42 km/h.

===== NARZEDZIA =====
Tego narzedzia uzywa sie do ciecia.
Tego narzedzia uzywa sie do wkrecania.

===== SPALINOWE =====
Poziom oleju wynosi 0.96.
Poziom oleju wynosi 0.65.

===== RECZNE =====
Do napedzenia tego urzadzenia uzywa sie nog.
Do napedzenia tego urzadzenia uzywa sie reki.

===== NAZWANE =====
To jest moje porsche.
Predkosc maksymalna tego pojazdu wynosi 286 km/h.
Poziom oleju wynosi 0.96.

Srubokret typu krzyzak.
Tego narzedzia uzywa sie do wkrecania.
Do napedzenia tego urzadzenia uzywa sie reki.

Wypisuje rower wigry3.
Predkosc maksymalna tego pojazdu wynosi 42 km/h.
Do napedzenia tego urzadzenia uzywa sie nog.

Pila spalinowa marki husqvarna.
Tego narzedzia uzywa sie do ciecia.
Poziom oleju wynosi 0.65.

*/
