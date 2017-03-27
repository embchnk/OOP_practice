// Nazwa pliku wykonywalnego: Magiel

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze napisac klasy reprezentujace zelazka marki zelmer i
// tefal. Kazde zelazko ma nazwe, cene i temperature (temperutara to
// liczba calkowita od 1 do 3).

// Prosze napisac klasy reprezentujace rozne rodzaje ubran. Kazde
// ubranie moze byc pogniecienie lub wyprasowane i mozna je prasowac
// lub gniesc. Oprocz tego ma swoja nazwe i cene. Dodatkowo koszule
// moga miec pogniecione lub wyprasowane rekawy, a spodnie moga miec
// pogniecione lub wyprasowane nogawki. Stan i prasowanie rekawow lub
// nogawek nie ma nic wspolnego z ogolnym stanem lub prasowaniem.

// SWIATLA PODPOWIEDZ
// Koszula nie ma nogawek, a spodnie nie maja rekawow.

// W zadaniu mozna korzystac z elementow bilbioteki standardowej
// zwlaszcza klasy std::string, ktora jest dostepna w pliku o nazwie
// "string".

// Pliku Main.cpp, nie wolno modyfikowac.

// Komentarz w kodzie mowia jakie wyjscie powinna generowac dana
// linia.

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

int main ()
{
  const float cenaZelazka = 135;
  ZelazkoZelmer pierwszeZelazko (cenaZelazka);
  pierwszeZelazko.UstawTemperature (3);
  pierwszeZelazko.WypiszWlasciwosci(); // Zelmer cena: 135. temperatura: 3

  const float cenaKoszuli = 200;
  KoszulaBawelniana koszulaPierwsza (cenaKoszuli);
  koszulaPierwsza.WypiszWlasciwosci(); // Koszula bawelniana cena: 200. Stan ubrania: pogniecione. Stan rekawow: pogniecione.
  koszulaPierwsza.Prasuj(pierwszeZelazko); // Prasuje Koszula bawelniana zelazkiem o temp. 3.
  koszulaPierwsza.WypiszWlasciwosci();	   // Koszula bawelniana cena: 200. Stan ubrania: wyprasowane. Stan rekawow: pogniecione.

  KoszulaJedwabna koszulaDruga (300); 
  koszulaDruga.WypiszWlasciwosci(); // Koszula jedwabna cena: 300. Stan ubrania: pogniecione. Stan rekawow: pogniecione.
  koszulaDruga.PrasujRekawy(pierwszeZelazko); // Prasuje rekawy Koszula jedwabna zelazkiem o temp.3.
  koszulaDruga.WypiszWlasciwosci();	      // Koszula jedwabna cena: 300. Stan ubrania: pogniecione. Stan rekawow: wyprasowane.
  
  SpodnieBawelniane spodniePierwsze (55);
  spodniePierwsze.WypiszWlasciwosci(); // Spodnie bawelniane cena: 55. Stan ubrania: pogniecione. Stan nogawek: pogniecione.
  spodniePierwsze.Prasuj(pierwszeZelazko); // Prasuje Spodnie bawelniane zelazkiem o temp. 3.
  spodniePierwsze.WypiszWlasciwosci();	   // Spodnie bawelniane cena: 55. Stan ubrania: wyprasowane. Stan nogawek: pogniecione.

  SpodnieJedwabne spodnieDrugie (234);
  spodnieDrugie.WypiszWlasciwosci(); // Spodnie jedwabne cena: 234. Stan ubrania: pogniecione. Stan nogawek: pogniecione.
  spodnieDrugie.PrasujNogawki(pierwszeZelazko); // Prasuje nogawki Spodnie jedwabne zelazkiem o temp.3
  spodnieDrugie.WypiszWlasciwosci();		// Spodnie jedwabne cena: 234. Stan ubrania: pogniecione. Stan nogawek: wyprasowane.


  Ubranie* koszUbran [4];
  koszUbran[0] = &koszulaPierwsza;
  koszUbran[1] = &koszulaDruga;
  koszUbran[2] = &spodniePierwsze;
  koszUbran[3] = &spodnieDrugie;

  std::cout<<"\n";
  std::cout<<"===== GNIECIEMY =====\n";
  Ubranie** koniecKosza = koszUbran + 4;
  for (Ubranie** ciuch = koszUbran; ciuch != koniecKosza; ++ciuch) {
    (*ciuch)->Pogniec();
    (*ciuch)->WypiszWlasciwosci();
    std::cout<<"\n";
  }
  std::cout<<"\n";

  ZelazkoTefal drugieZelazko (333);
  drugieZelazko.UstawTemperature (1);
  drugieZelazko.WypiszWlasciwosci(); // Tefal cena: 333. temperatura: 1

  std::cout<<"\n";
  std::cout<<"===== PRASUJEMY =====\n";
  for (Ubranie** ciuch = koszUbran; ciuch != koniecKosza; ++ciuch) {
    (*ciuch)->Prasuj(drugieZelazko);
    (*ciuch)->WypiszWlasciwosci();
    std::cout<<"\n";
  }
  
  return 0;
}
/*
Zelmer cena: 135. temperatura: 3
Koszula bawelniana cena: 200. Stan ubrania: pogniecione. Stan rekawow: pogniecione.
Prasuje Koszula bawelniana zelazkiem o temp. 3.
Koszula bawelniana cena: 200. Stan ubrania: wyprasowane. Stan rekawow: pogniecione.
Koszula jedwabna cena: 300. Stan ubrania: pogniecione. Stan rekawow: pogniecione.
Prasuje rekawy Koszula jedwabna zelazkiem o temp.3.
Koszula jedwabna cena: 300. Stan ubrania: pogniecione. Stan rekawow: wyprasowane.
Spodnie bawelniane cena: 55. Stan ubrania: pogniecione. Stan nogawek: pogniecione.
Prasuje Spodnie bawelniane zelazkiem o temp. 3.
Spodnie bawelniane cena: 55. Stan ubrania: wyprasowane. Stan nogawek: pogniecione.
Spodnie jedwabne cena: 234. Stan ubrania: pogniecione. Stan nogawek: pogniecione.
Prasuje nogawki Spodnie jedwabne zelazkiem o temp.3
Spodnie jedwabne cena: 234. Stan ubrania: pogniecione. Stan nogawek: wyprasowane.

===== GNIECIEMY =====
Koszula bawelniana cena: 200. Stan ubrania: pogniecione.
Koszula jedwabna cena: 300. Stan ubrania: pogniecione.
Spodnie bawelniane cena: 55. Stan ubrania: pogniecione.
Spodnie jedwabne cena: 234. Stan ubrania: pogniecione.

Tefal cena: 333. temperatura: 1

===== PRASUJEMY =====
Prasuje Koszula bawelniana zelazkiem o temp. 1.
Koszula bawelniana cena: 200. Stan ubrania: wyprasowane.
Prasuje Koszula jedwabna zelazkiem o temp. 1.
Koszula jedwabna cena: 300. Stan ubrania: wyprasowane.
Prasuje Spodnie bawelniane zelazkiem o temp. 1.
Spodnie bawelniane cena: 55. Stan ubrania: wyprasowane.
Prasuje Spodnie jedwabne zelazkiem o temp. 1.
Spodnie jedwabne cena: 234. Stan ubrania: wyprasowane.
*/
