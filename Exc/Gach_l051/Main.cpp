// Nazwa pliku wykonywalnego: RuchomeObrazki

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze napisac klasy reprezentujace monitor, rzutnik i telewizor
// LCD. Kazde z tych urzadzen wyswietla obraz w inny sposob,
// tzn. dodaje innego rodzaju ramke do obrazu i ma wymiary
// zdefiniowane w programie. Kazde z tych urzadzen moze byc uzyte do
// wyswietlenia z obrazu z komputera lub odtwarzacza DVD. Komputer
// zapelnia obraz literami K, a odtwarzacz DVD literami D. Informacja,
// ktora jest wyswietlana (oprocz ramki) nie moze znajdowac sie w
// monitorze, rzutniku lub telewizorze.

// W zadaniu mozna korzystac z elementow bilbioteki standardowej
// zwlaszcza klasy std::string, ktora jest dostepna w pliku o nazwie
// "string".

// Pliku Main.cpp, nie wolno modyfikowac.

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
// wgrac do UPEL.

#include"Main.h"

int main ()
{
  Komputer komputerStacjonarny;	// wyswietla 'k'

  const int szerokoscWZnakach = 14;
  const int wysokoscWZnakach = 4;
  Monitor monitorBiurowy(szerokoscWZnakach, wysokoscWZnakach);
  
  monitorBiurowy.Wyswietl(komputerStacjonarny);
  std::cout<<"\n\n";

  Rzutnik rzutnikKlasowy (16, 3);
  rzutnikKlasowy.Wyswietl(komputerStacjonarny);
  std::cout<<"\n\n";
  
  const TelewizorLCD telewizorDomowy (17, 6);
  telewizorDomowy.Wyswietl(komputerStacjonarny);
  std::cout<<"\n\n";

  OdtwarzaczDVD taniOdtwarzacz;
  monitorBiurowy.Wyswietl(taniOdtwarzacz);
  std::cout<<"\n\n";

  rzutnikKlasowy.Wyswietl(taniOdtwarzacz);
  std::cout<<"\n\n";

  telewizorDomowy.Wyswietl(taniOdtwarzacz);
  
  return 0;
}
/*
Polaczono monitor i komputer
++++++++++++++
++++++++++++++
KKKKKKKKKKKKKK
KKKKKKKKKKKKKK
KKKKKKKKKKKKKK
KKKKKKKKKKKKKK
++++++++++++++
++++++++++++++


Polaczono rzutnik i komputer
KKKKKKKKKKKKKKKK
KKKKKKKKKKKKKKKK
KKKKKKKKKKKKKKKK


Polaczono telewizor i komputer
*****************
KKKKKKKKKKKKKKKKK
KKKKKKKKKKKKKKKKK
KKKKKKKKKKKKKKKKK
KKKKKKKKKKKKKKKKK
KKKKKKKKKKKKKKKKK
KKKKKKKKKKKKKKKKK
* * * * * * * * * 
 & & & & & & & &
* * * * * * * * * 


Polaczono monitor i DVD
++++++++++++++
++++++++++++++
DDDDDDDDDDDDDD
DDDDDDDDDDDDDD
DDDDDDDDDDDDDD
DDDDDDDDDDDDDD
++++++++++++++
++++++++++++++


Polaczono rzutnik i DVD
DDDDDDDDDDDDDDDD
DDDDDDDDDDDDDDDD
DDDDDDDDDDDDDDDD


Polaczono telewizor i DVD
*****************
DDDDDDDDDDDDDDDDD
DDDDDDDDDDDDDDDDD
DDDDDDDDDDDDDDDDD
DDDDDDDDDDDDDDDDD
DDDDDDDDDDDDDDDDD
DDDDDDDDDDDDDDDDD
* * * * * * * * * 
 & & & & & & & &
* * * * * * * * * 
*/
