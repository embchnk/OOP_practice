// Nazwa pliku wykonywalnego: Postacie

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze dopisac klasy tak aby na ekranie wypisywal sie odpowiedni tekst i tworzyly sie pliki .txt z odpowiednia trescia.

// W zadaniu NIE wolno korzystac z std::string.

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
#include<fstream>
#include<sstream>

std::ofstream* OtworzPlik ()
{
  static int numerPliku = 1;
  std::stringstream nazwaPliku;
  nazwaPliku <<"Plik"<< numerPliku++<<".txt";
  std::ofstream* plik = new std::ofstream;
  plik->open (nazwaPliku.str().data());

  return plik;
}

void Wypisz (ObiektWypisz_t obiekt)
{
  std::cout<<obiekt<<"\n";

  std::ofstream* plik = OtworzPlik();
  (*plik)<<obiekt<<"\n";
  delete plik;
}

void WypiszMezczyzna (ObiektWypiszMezczyzna_t obiekt)
{
  std::cout<<obiekt<<"\n";

  std::ofstream* plik = OtworzPlik();
  (*plik)<<obiekt<<"\n";
  delete plik;
}

void WypiszKobieta (ObiektWypiszKobieta_t obiekt)
{
  std::cout<<obiekt<<"\n";

  std::ofstream* plik = OtworzPlik();
  (*plik)<<obiekt<<"\n";
  delete plik;
}

void WypiszDobrze (ObiektWypiszDobrze_t obiekt)
{
  std::cout<<obiekt<<"\n";

  std::ofstream* plik = OtworzPlik();
  (*plik)<<obiekt<<"\n";
  delete plik;
}

int main ()
{
  using namespace std;
  
  Leela* pierwszaLeela =  new Leela (26);
  const Leela drugaLeela (28);
  const Kobieta* pierwszaKobieta = pierwszaLeela;
  Postac* pierwszaPostac = pierwszaLeela;

  cout<<"========== Wskazniki Leela ==========\n";

  cout<<*pierwszaPostac<<"\n";
  cout<<*pierwszaKobieta<<"\n";
  cout<<*pierwszaLeela<<"\n";
  cout<<drugaLeela<<"\n";

  cout<<"========== Wypisz  ==========\n";
  Wypisz(*pierwszaKobieta);
  Wypisz(drugaLeela);

  cout<<"========== Wypisz Kobieta ==========\n";
  WypiszKobieta(*pierwszaKobieta);
  WypiszKobieta(drugaLeela);

  cout<<"========== Wypisz dobrze Leela ==========\n";
  WypiszDobrze(*pierwszaKobieta);
  WypiszDobrze(drugaLeela);
  WypiszDobrze(*pierwszaPostac);

  delete pierwszaPostac;

  Fry pierwszyFry (1030);
  Mezczyzna* pierwszyMezczyzna = &pierwszyFry;
  Postac* drugaPostac = &pierwszyFry;

  Fry* drugiFry = new Fry (1025);
  
  cout<<"========== Wskazniki Fry ==========\n";
  cout<<pierwszyFry<<"\n";
  cout<<*pierwszyMezczyzna<<"\n";
  cout<<*drugaPostac<<"\n";
  cout<<*drugiFry<<"\n";

  cout<<"========== Wypisz  ==========\n";
  Wypisz(pierwszyFry);
  Wypisz(*drugiFry);

  cout<<"========== Wypisz Mezczyzna ==========\n";
  WypiszMezczyzna(pierwszyFry);
  WypiszMezczyzna(*drugiFry);

  cout<<"========== Wypisz dobrze Fry ==========\n";
  WypiszDobrze(pierwszyFry);
  WypiszDobrze(*drugiFry);
  WypiszDobrze(*drugaPostac);

  delete drugiFry;

  return 0;
}
/*
========== Wskazniki Leela ==========
Leela 26.
Leela 26.
Leela 26.
Leela 28.
========== Wypisz  ==========
Postac ma 26 lat.
Postac ma 28 lat.
========== Wypisz Kobieta ==========
Kobieta w wieku 26 lat.
Kobieta w wieku 28 lat.
========== Wypisz dobrze Leela ==========
Leela 26.
Leela 28.
Leela 26.
========== Wskazniki Fry ==========
Fry ma 1030 lat.
Fry ma 1030 lat.
Fry ma 1030 lat.
Fry ma 1025 lat.
========== Wypisz  ==========
Postac ma 1030 lat.
Postac ma 1025 lat.
========== Wypisz Mezczyzna ==========
Wiek mezczyzny to 1030.
Wiek mezczyzny to 1025.
========== Wypisz dobrze Fry ==========
Fry ma 1030 lat.
Fry ma 1025 lat.
Fry ma 1030 lat.
*/
