// Nazwa pliku wykonywalnego: Fraction

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze napisac klase Fraction, ktora reprezentuje ulamek i
// zaimplementowac odpowiednie operatory oraz funkcjonalnosc. Klasa
// Fraction powinna miec "glosne" konstruktory i destruktor, tzn. przy
// tworzeniu i usuwaniu obiektu powinien byc wypisywany komunikat na
// ekran.

// Prosze napisac klase FractionPointer, ktora bedzie "sprytnym
// wskaznikiem" na obiekt typu Fraction. Oznacza, to ze jezeli
// zostanie usuniety ostatni obiekt FractionPointer wskazujacy na dany
// obiekt, to obiekt ten jest usuwany. Prosze zaimplementowc wszystkie
// potrzebne operatory. Przy rozwiazaniu tego zadania moze byc pomocna
// klasa std::vector<Fraction*>. Aby dodac element do wektora mozna
// wykorzystac metode
// std::vector<Fraction*>::push_back(Fraction*). Aby usunac element o
// znanym indeksie z wektora mozna uzyc metody
// std::vector<Fraction*>::erase(vectorObject.begin() + index).

// Prosze zaimplemntowac tylko te operatory i funkcje, ktore sa
// wykorzystywane w funkcji main i ktore trzeba
// zaimplementowac. Implementacja zupelnie zbednych funkcji lub
// operatorow bedzie obnizala ocene.

// Pliku Main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod). 

// Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie Fraction. Program nalezy kompilowac z flagami -Wall -g.

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

  Fraction staticFraction (5, 15);
  cout<<staticFraction<<"\n";

  FractionPointer dynamicFrac1 = new Fraction (4, 16);
  dynamicFrac1->Print();

  {
    FractionPointer dynamicFrac2 = dynamicFrac1;
    dynamicFrac2 *=* dynamicFrac1;
    cout<<"FIRST: "<<staticFraction<<"\t"<<*dynamicFrac1<<"\t"<<*dynamicFrac2<<"\n";

    FractionPointer dynamicFrac3 = new Fraction (6, 8);
    dynamicFrac3->Print();

    cout<<"PRODUCT: "<<dynamicFrac2*dynamicFrac3<<"\n";

    Fraction::Action x = &Fraction::Simplify;

   	dynamicFrac1->*x;
    dynamicFrac2->*x;
    dynamicFrac3->*x;

    cout<<"X: "<<*dynamicFrac1<<"\t"<<*dynamicFrac2<<"\t"<<*dynamicFrac3<<"\n";

    dynamicFrac3 = dynamicFrac1 = dynamicFrac2;
    cout<<"EQUAL: "<<staticFraction<<"\t"<<*dynamicFrac1<<"\t"<<*dynamicFrac2<<"\t"<<*dynamicFrac3<<"\n";
  }
  
  {
    cout<<"LAST: "<<staticFraction<<"\t"<<*dynamicFrac1<<"\n";
  }
  
  return 0;
}
/*
Creating: 5/15
5/15
Creating: 4/16
4/16
FIRST: 5/15	16/256	16/256
Creating: 6/8
6/8
Creating: 96/2048
PRODUCT: 96/2048
Destroying: 96/2048
X: 1/16	1/16	3/4
Destroying: 3/4
EQUAL: 5/15	1/16	1/16	1/16
LAST: 5/15	1/16
Destroying: 1/16
Destroying: 5/15
 */
