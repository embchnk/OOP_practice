// Nazwa pliku wykonywalnego: Vector

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// UWAGA
// Do rozwiazania zadanie nie wolno wykorzystywac nic z biblioteki
// standardowej oprocz cout i endl

// Prosze napisac prosta klase TestObject, ktora bedzie przechowywala
// numer ID i miala funkcje Print, wypisujaca informacjje o tym
// obiekcie. Prosze rowniez zaimplementowac funkcjje Set, ktora
// ustawia numer ID.

// Prosze napisac "cos" czego bedzie dalo sie uzywac jak
// tablice. Tylko jedna tego typu tablica moze istniec w
// programie. Tablica moze przechowywac rozne typy.

// Prosze zwrocic uwage na zarzadzanie pamiecia.

// Pliku Main.cpp nie wolno modyfikowac.

// Komentarze w kodzie informuja jaki tekst na ekranie wypisuje dana
// linia kodu.

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

#include<iostream>
#include"Main.h"

int main ()
{
  const int intSize (3);
  Vector::Initialise<int>(intSize);
  Vector::At<int>(0) = 4;
  Vector::At<int>(1) = 2;
  Vector::At<int>(2) = 5;

  std::cout<<"Integers: "<<Vector::At<int>(0)<<" "<<Vector::At<int>(1)<<" "<<Vector::At<int>(2)<<"\n"; // Integers: 4 2 5

  Vector::Reset<int>();

  std::cout<<"===== First Object TEST =====\n";
  TestObject firstObj (1);
  firstObj.Print();

  std::cout<<"===== First Object =====\n";
  const int objSize (4);
  Vector::Initialise (objSize, firstObj);
  for (int i = 0; i < Vector::Size(); ++i)
    Vector::At<TestObject>(i).Print();

  std::cout<<"===== MODIFIED First Object =====\n";

  Vector::At<TestObject>(1).Set(10);
  Vector::At<TestObject>(2).Set(20);
  Vector::At<TestObject>(3).Set(30);

  for (int i = 0; i < Vector::Size(); ++i)
    Vector::At<TestObject>(i).Print();

  Vector::Reset<TestObject>();
  Vector::Reset<TestObject>();


  std::cout<<"===== Second Object =====\n";

  const TestObject* secondObj = new const TestObject(2000);

  const int objSize2 (6);
  Vector::Initialise (objSize2, secondObj);
  for (int i = 0; i < objSize2; ++i)
    Vector::At<const TestObject*>(i)->Print();

  std::cout<<"===== Modified Second Object =====\n";

  Vector::At<const TestObject*>(1) = new const TestObject (100);
  Vector::At<const TestObject*>(2) = new TestObject (110);
  Vector::At<const TestObject*>(3) = new TestObject (120);
  Vector::At<const TestObject*>(4) = new TestObject (130);
  Vector::At<const TestObject*>(5) = new TestObject (140);

  for (int i = 0; i < Vector::Size(); ++i)
    Vector::At<const TestObject*>(i)->Print();

  for (int i = 0; i < Vector::Size(); ++i)
    delete Vector::At<const TestObject*>(i);

  Vector::Reset<const TestObject*>();

  return 0;
}
/*
Integers: 4 2 5
===== First Object TEST =====
Object with ID=1
===== First Object =====
Object with ID=1
Object with ID=1
Object with ID=1
Object with ID=1
===== MODIFIED First Object =====
Object with ID=1
Object with ID=10
Object with ID=20
Object with ID=30
===== Second Object =====
Object with ID=2000
Object with ID=2000
Object with ID=2000
Object with ID=2000
Object with ID=2000
Object with ID=2000
===== Modified Second Object =====
Object with ID=2000
Object with ID=100
Object with ID=110
Object with ID=120
Object with ID=130
Object with ID=140
*/
