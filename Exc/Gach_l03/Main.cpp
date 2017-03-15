// Nazwa pliku wykonywalnego: Lista

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze napisac liste liczb calkowitych. Pamiec powinna byc
// alokowana dynamicznie i lista powinna obslugiwac dowolna liczbe
// elementow.

// Prosze zaimplemntowac tylko te operatory i funkcje, ktore sa
// wykorzystywane w funkcji main i ktore trzeba
// zaimplementowac. Implementacja zupelnie zbednych funkcji lub
// operatorow bedzie obnizala ocene.

// Pliku Main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod). 

// Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie Complex. Program nalezy kompilowac z flagami -Wall -g.

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

  Lista pierwsza;
  pierwsza = pierwsza + 2 + 3 + 5;
  cout<<"Pierwsza: "<<pierwsza<<"\n"; // Pierwsza: 2 3 5

  pierwsza + 4 + 6;
  cout<<"Pierwsza II: "<<pierwsza<<"\n"; // Pierwsza II: 2 3 5
/*
  pierwsza[0] = 3;
  pierwsza[1] = 2;
  cout<<"Pierwsza III: "<<pierwsza<<"\n"; // Pierwsza III: 3 2 5

  pierwsza += 7;

  cout<<"Pierwsza IV: "<<pierwsza<<"\n"; // Pierwsza IV: 3 2 5 7

  int tablica [] = {2, 4, 6, 8, 10};
  Lista parzysta (tablica, sizeof(tablica)/sizeof(int));

  cout<<"Parzysta: "<<parzysta<<"\n"; // Parzysta: 2 4 6 8 10

  Lista suma = pierwsza + parzysta;
  cout<<"Suma: "<<suma<<"\n";	// Suma: 3 2 5 7 2 4 6 8 10

  const Lista::Iterator koniec = suma.koniec();
  for (Lista::Iterator liczba = suma.poczatek(); liczba != koniec; ++liczba)
    cout <<*liczba<<", ";
  cout<<*suma.koniec()<<"\n";	// 3, 2, 5, 7, 2, 4, 6, 8, 10
  
  suma[1] = suma[5] = 33;
  cout<<"Pierwsza V: "<<pierwsza<<"\n"; // Pierwsza V: 3 2 5 7
  cout<<"Przysta II: "<<parzysta<<"\n"; // Przysta II: 2 4 6 8 10
  cout<<"Suma II: "<<suma<<"\n";	// Suma II: 3 33 5 7 2 33 6 8 10

  parzysta = pierwsza;
  cout<<"Pierwsza VI: "<<pierwsza<<"\n"; // Pierwsza VI: 3 2 5 7
  cout<<"Przysta III: "<<parzysta<<"\n"; // Przysta III: 3 2 5 7
  cout<<"Suma III: "<<suma<<"\n";	 // Suma III: 3 33 5 7 2 33 6 8 10
*/

  return 0;
}
/*
Pierwsza: 2 3 5
Pierwsza II: 2 3 5
Pierwsza III: 3 2 5
Pierwsza IV: 3 2 5 7
Parzysta: 2 4 6 8 10
Suma: 3 2 5 7 2 4 6 8 10
3, 2, 5, 7, 2, 4, 6, 8, 10
Pierwsza V: 3 2 5 7
Przysta II: 2 4 6 8 10
Suma II: 3 33 5 7 2 33 6 8 10
Pierwsza VI: 3 2 5 7
Przysta III: 3 2 5 7
Suma III: 3 33 5 7 2 33 6 8 10
  
 */
