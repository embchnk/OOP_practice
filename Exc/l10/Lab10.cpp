// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Proszę napisac taki kod, ktory pozwoli reprezentowac zmienne
// roznych typow. Kazda zmienna przechowuje nazwe i wartosc. Jest
// mozliwosc przechowywania wszystkich zmiennych w jednej
// tablicy. Dodatkowo prosze zaimplementowac klase szablonowa
// reprezentujaca zeminna z jednostkami.

// UWAGA!
// Funkcja ArrayOfVariables::CreateAndAdd moze byc zaimplementowana
// tylko JEDEN raz i nie wolno w niej używać żadnych instrukcji
// warunkowych np. if, for, while.

// UWAGA!
// Po uruchomieniu kodu znajdujacego sie w blokach ifdef ERROR_1 i
// ERROR_2 w kazdej z linii uruchomionego bloku powinien pojawic sie
// blad kompilacji. Jezeli blad sie nie pojawi oznacza to nieprawna
// kompilacje, a wiec 0 punktow.

// Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie Lab10. Program nalezy kompilowac z flagami -Wall -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Pliku Lab10.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod). Powinien działac dla dowolnej
// liczby przekształceń.

// Zadanie nalezy rozwiazac samodzielnie, a przy jego wykonaniu nie
// wolno korzystać z internetu, notatek, ani żadnych innych materialow
// (w tym własnych wcześniej przygotowanych plików).

// Rozwiazanie zadania powinno znajdowac sie w katalogu Lab10,
// czyli tam gdzie jest ten plik.


#include"Lab10.h"
#include<iostream>

#define ERROR_0
#define ERROR_1
#define ERROR_2

int main ()
{
  const unsigned int maxArraySize = 10;
  ArrayOfVariables array (maxArraySize);

  std::cout<<"----- VARIABLES PRINT -----\n";
  VariableDouble* time = NULL;
  time = array.CreateAndAdd ("time", 13.);
  time->Print();
  
  VariableFloat* distance = NULL;
  distance = array.CreateAndAdd ("distance", 15.f);
  distance->Print();
  
  VariableInt* numberOfEvents = array.CreateAndAdd ("events", 176);
  VariableChar* hexDigit = array.CreateAndAdd ("hex digit", 'F');
  VariableBool* isGood = array.CreateAndAdd ("is good", true);

#ifdef ERROR_0
  VariableInt* numberOfEvents2 = array.CreateAndAdd ("events", 176.);
#endif
  
#ifdef ERROR_1
  time = distance;
  time = numberOfEvents;
  time = isGood;
  time = hexDigit;
  distance = numberOfEvents;
  distance = isGood;
  numberOfEvents = isGood;
#endif
  
  std::cout<<"----- ARRAY PRINT -----\n";
  array.Print();
  std::cout<<std::endl;

  std::cout<<"----- MODIFIED VALUES -----\n";
  time->SetValue(10.5);
  distance->SetValue(0.5);
  numberOfEvents->SetValue (42);
  hexDigit->SetValue('9');
  isGood->SetValue(true);

  array.Print();
  std::cout<<std::endl;
  
  std::cout<<"----- WITH UNITS -----\n";
  VariableWithUnits<double> speed ("speed", 333., "m/s");
  speed.Print();
  VariableDouble& speedRef = speed;
  speedRef.Print();

  VariableWithUnits<int> numberOfAtoms ("number of atoms", 436, "atoms");
  numberOfAtoms.Print();
  VariableInt& numberOfAtomsRef = numberOfAtoms;
  numberOfAtomsRef.Print();

#ifdef ERROR_2
  VariableWithUnits<double>& speedRef2 = speedRef;
  VariableWithUnits<int>& numberRef = numberOfAtomsRef;
#endif
  
  return 0;
}
/*
----- VARIABLES PRINT -----
time: 13
distance: 15
----- ARRAY PRINT -----
time: 13
distance: 15
events: 176
hex digit: F
is good: 1

----- MODIFIED VALUES -----
time: 10.5
distance: 0.5
events: 42
hex digit: 9
is good: 1

----- WITH UNITS -----
speed: 333 [m/s]
speed: 333 [m/s]
number of atoms: 436 [atoms]
number of atoms: 436 [atoms]
*/
