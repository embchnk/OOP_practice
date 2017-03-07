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
// wskaznikiem" na obiekt typu Fraction. Ma to byc "uqniue pointer",
// tzn. tylko jeden obiekt typu FractionPointer w danej chwili moze
// przechowywac wskaznik na jeden obiekt typu Fraction. Nie moze byc
// sytuacji, ze jednoczesnie dwa obiekty typu FractionPointer wskazuja
// na ten sam obiekt typu Fraction. Dodatkowo, gdy tracony jest adres
// przechowywany we FractionPointer, np. gdy FractionPointer jest
// usuwany lub nadpisywany, to obiekt typu Fraction jest usuwany.

// Trzecia klasa, ktora nalezy zaimplementowac jest
// FractionRegister. Jest to "singleton", czyli istnieje tylko jeden
// obiekt tej klasy.

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

void TimesTwo (Fraction* frac)
{
  frac->Numerator() *= 2;
  frac->Denominator() *= 2;
}

int main ()
{
  using namespace std;

  Fraction staticFraction (5, 15);
  cout<<staticFraction<<"\n";

  {
    FractionRegister* fractions = new FractionRegister();
    *fractions << staticFraction;
    cout<<*fractions<<"\n";
  } 

  FractionPointer dynamicFrac1 = new Fraction (4, 16);
  cout<<dynamicFrac1<<"\n";
  {
    FractionPointer dynamicFrac2 = dynamicFrac1;
    cout<<"FIRST: "<<staticFraction<<"\t"<<dynamicFrac1<<"\t"<<dynamicFrac2<<"\n";

    FractionPointer dynamicFrac3 = new Fraction (6, 8);
    cout<<dynamicFrac3<<"\n";
    TimesTwo (dynamicFrac3);
    cout<<"Times two: "<<dynamicFrac3<<"\n";
    
    dynamicFrac3 = dynamicFrac2 = dynamicFrac2;
    cout<<"EQUAL: "<<"\t"<<dynamicFrac1<<"\t"<<dynamicFrac2<<"\t"<<dynamicFrac3<<"\n";

    {
      FractionRegister* fractions = new FractionRegister;
      *fractions << staticFraction<<dynamicFrac3;
      cout<<*fractions<<"\n";
    }
    
  }

  FractionRegister* fractions = new FractionRegister;
  cout<<*fractions<<"\n";

  return 0;
}
/*
Creating 5/15
address=0x7ffc9caf5340 value=5/15
0x7ffc9caf5340
Creating 4/16
[pointing to address=0x890c50 value=4/16]
FIRST: address=0x7ffc9caf5340 value=5/15	[pointing to 0]	[pointing to address=0x890c50 value=4/16]
Creating 6/8
[pointing to address=0x890c70 value=6/8]
Times two: [pointing to address=0x890c70 value=12/16]
Destroying 12/16
EQUAL: 	[pointing to 0]	[pointing to 0]	[pointing to address=0x890c50 value=4/16]
0x7ffc9caf5340 0x7ffc9caf5340 0x890c50
Destroying 4/16
0x7ffc9caf5340 0x7ffc9caf5340 0x890c50
Destroying 5/15
 */
