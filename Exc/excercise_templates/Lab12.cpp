// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Nalezy zaimplementowac taki kod, ktory pozwoli realizowac dzialania
// zgodnie z zasadami obowiazujacymi w fizyce, to znaczy mnozyc i
// dzielicprzez siebie mozna dowolne liczby, ale dodawac i odjemowac
// jedynie liczby o tej samej jednostce.

// UWAGA!!!
// Rozwiazanie powinno dzialac dla dowolnych poteg metra, rowniez
// tych, ktore nie sa wypisane w tym programie. Jezeli kod nie bedzie
// obslugiwal dowolnych jednostek bedzie to uznawane za blad
// kompilacji.

// Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie Lab12. Program nalezy kompilowac z flagami -Wall -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Pliku Lab12.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod). Powinien działać dla dowolnej
// liczby przekształceń.

// Przy wykonaniu zadania nie wolno korzystać z internetu, notatek,
// ani żadnych innych materiałów (w tym własnych wcześniej
// przygotowanych plików)

// Kody źródłowe muszą znajdować się w katalogu ~/oop/lab_LABNR. Prawa
// do tego katalogu muszą być równe 700 (tylko dostęp dla
// właściciela).

// Skonczone zadanie nalezy wyslac uruchamiajac skrypt 
// ~gach/WyslijZadanie.sh
// bedac w katalogu zawierajacym rozwiazanie czyli ~/oop/lab_12

#include"Lab12.h"
#include<iostream>

//#define ERROR1
//#define ERROR2

int main ()
{
  using namespace std;
  
  Metr dlugosc (4);
  Metr szerokosc (5);
  Metr wysokosc (2.5);
  MetrKwadratowy powierzchnia = dlugosc*szerokosc;
  MetrSzescienny objetosc = dlugosc*szerokosc*wysokosc;
  Metr obwod = dlugosc + dlugosc + szerokosc + szerokosc;
  MetrKwadratowy podwojnaPowierzchnia = powierzchnia + powierzchnia;
  MetrKwadratowy obliczonaPowierzchnia = objetosc/wysokosc;
  MetrKwadratowy odjetaPowierzchnia = podwojnaPowierzchnia - powierzchnia;
  Metr obliczonaWysokosc = objetosc/powierzchnia;

#ifdef ERROR1
  dlugosc + powierzchnia;
  dlugosc + objetosc;
  objetosc + powierzchnia;

  dlugosc - powierzchnia;
  dlugosc - objetosc;
  objetosc - powierzchnia;
#endif
  
  // std::cout<<"--- Wymiary pokoju ---\n";
  // std::cout<<"dlugosc: "<<dlugosc<<"\n";
  // std::cout<<"szerokosc: "<<szerokosc<<"\n";
  // std::cout<<"wysokosc: "<<wysokosc<<"\n";
  // std::cout<<"powierzchnia: "<<powierzchnia<<"\n";
  // std::cout<<"objetosc: "<<objetosc<<"\n";
  // std::cout<<"obwod: "<<obwod<<"\n";
  // std::cout<<"podwojnaPowierzchnia: "<<podwojnaPowierzchnia<<"\n";
  // std::cout<<"obliczonaPowierzchnia: "<<obliczonaPowierzchnia<<"\n";
  // std::cout<<"odjetaPowierzchnia: "<<odjetaPowierzchnia<<"\n";
  // std::cout<<"obliczonaWysokosc: "<<obliczonaWysokosc<<"\n";

  // std::cout<<"\nPotegi dlugosci:\n";
  // std::cout<<dlugosc*dlugosc<<"\n";
  // std::cout<<dlugosc*dlugosc*dlugosc<<"\n";
  // std::cout<<dlugosc*dlugosc*dlugosc*dlugosc<<"\n";
  // std::cout<<dlugosc*dlugosc*dlugosc*dlugosc*dlugosc<<"\n";
  // std::cout<<dlugosc*dlugosc*dlugosc*dlugosc*dlugosc*dlugosc<<"\n";
  // std::cout<<dlugosc*dlugosc*dlugosc*dlugosc*dlugosc*dlugosc*dlugosc<<"\n";
  // std::cout<<dlugosc*dlugosc*dlugosc*dlugosc*dlugosc*dlugosc*dlugosc*dlugosc<<"\n";

  // std::cout<<"\nPodwojone potegi dlugosci:\n";
  // std::cout<<dlugosc*dlugosc + dlugosc*dlugosc<<"\n";
  // std::cout<<dlugosc*dlugosc*dlugosc + dlugosc*dlugosc*dlugosc<<"\n";
  // std::cout<<dlugosc*dlugosc*dlugosc*dlugosc + dlugosc*dlugosc*dlugosc*dlugosc<<"\n";
  // std::cout<<dlugosc*dlugosc*dlugosc*dlugosc*dlugosc + dlugosc*dlugosc*dlugosc*dlugosc*dlugosc<<"\n";
  // std::cout<<dlugosc*dlugosc*dlugosc*dlugosc*dlugosc*dlugosc + dlugosc*dlugosc*dlugosc*dlugosc*dlugosc*dlugosc<<"\n";
  // std::cout<<dlugosc*dlugosc*dlugosc*dlugosc*dlugosc*dlugosc*dlugosc + dlugosc*dlugosc*dlugosc*dlugosc*dlugosc*dlugosc*dlugosc<<"\n";
  // std::cout<<dlugosc*dlugosc*dlugosc*dlugosc*dlugosc*dlugosc*dlugosc*dlugosc + dlugosc*dlugosc*dlugosc*dlugosc*dlugosc*dlugosc*dlugosc*dlugosc<<"\n";
  

#ifdef ERROR2
  std::cout<<dlugosc + dlugosc*dlugosc<<"\n";
  std::cout<<dlugosc*dlugosc + dlugosc*dlugosc*dlugosc<<"\n";
  std::cout<<dlugosc*dlugosc*dlugosc + dlugosc*dlugosc*dlugosc*dlugosc<<"\n";
  std::cout<<dlugosc*dlugosc*dlugosc*dlugosc + dlugosc*dlugosc*dlugosc*dlugosc*dlugosc<<"\n";
  std::cout<<dlugosc*dlugosc*dlugosc*dlugosc*dlugosc + dlugosc*dlugosc*dlugosc*dlugosc*dlugosc*dlugosc<<"\n";
  std::cout<<dlugosc*dlugosc*dlugosc*dlugosc*dlugosc*dlugosc + dlugosc*dlugosc*dlugosc*dlugosc*dlugosc*dlugosc*dlugosc<<"\n";
  std::cout<<dlugosc*dlugosc*dlugosc*dlugosc*dlugosc*dlugosc*dlugosc + dlugosc*dlugosc*dlugosc*dlugosc*dlugosc*dlugosc*dlugosc*dlugosc<<"\n";
#endif

}

/*
--- Wymiary pokoju ---
dlugosc: 4 m
szerokosc: 5 m
wysokosc: 2.5 m
powierzchnia: 20 m^2
objetosc: 50 m^3
obwod: 18 m
podwojnaPowierzchnia: 40 m^2
obliczonaPowierzchnia: 20 m^2
odjetaPowierzchnia: 20 m^2
obliczonaWysokosc: 2.5 m

Potegi dlugosci:
16 m^2
64 m^3
256 m^4
1024 m^5
4096 m^6
16384 m^7
65536 m^8

Podwojone potegi dlugosci:
32 m^2
128 m^3
512 m^4
2048 m^5
8192 m^6
32768 m^7
131072 m^8
*/
