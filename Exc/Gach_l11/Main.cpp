// Nazwa pliku wykonywalnego: Pointer

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze szablon UniquePointer, ktory bedzie przechowywal adres
// obiektu. Moze istniec tylko jeden obiekt przechowujacy ten sam
// adres. Gdy obiekt typu UniqeuPointer jest niszczony, niszczony
// powinien byc rowniez obiekt na ktory wskazuje.

// Prosze napisac prosta klase Object, ktora bedzie przchowywala nazwe
// np. w postaci std::string i miala mozliwosc wypisywania na ekran.

// UWAGA
// W zadaniu bardzo wazne jest zarzadzanie pamiecia, dlatego za kazdy
// problem z pamiecia bedzie odejmowany 1 punkt.

// Pliku Main.cpp, nie wolno modyfikowac.

// Komentarz w kodzie mowia jakie wyjscie powinna generowac dana
// linia.

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

void AddToInt (int* val)
{
  *val += 2;
}

void PrintObject (const Object* obj)
{
  obj->Print();
}

int main ()
{
  using namespace std;

  std::cout<<"===== INT =====\n";
  UniquePointer<int> dynamicInt1 = new int (4);
  std::cout<<"pointer: "<<dynamicInt1<<"\n"; // pointer: [pointing to <adres>]
  std::cout<<"value: "<<*dynamicInt1<<"\n";  // value: 4
  {
    UniquePointer<int> dynamicInt2 = dynamicInt1;
    std::cout<<"pointer in braces: "<<dynamicInt1<<"   "<<dynamicInt2<<"\n"; // pointer in braces: [pointing to 0]   [pointing to <adres>]
    std::cout<<"value in braces: "<<*dynamicInt2<<"\n"; // value in braces: 4

    UniquePointer<int> dynamicInt3 = new int (6);
    cout<<"pointer: "<<dynamicInt3<<"   value: "<<*dynamicInt3<<"\n"; // pointer: [pointing to <adres>]   value: 6
    AddToInt (dynamicInt3);
    cout<<"Add two: "<<*dynamicInt3<<"\n"; // Add two: 8
    
    dynamicInt3 = dynamicInt2 = dynamicInt2;
    cout<<"EQUAL: "<<"\t"<<dynamicInt1<<"\t"<<dynamicInt2<<"\t"<<dynamicInt3<<"\n"; // EQUAL: 	[pointing to 0]	[pointing to 0]	[pointing to <adres>]
    cout<<"value dynamicInt3: "<<*dynamicInt3<<"\n"; // value dynamicInt3: 4
  }

  std::cout<<"===== OBJECT =====\n";
  UniquePointer<const Object> dynamicObject1 = new Object ("Frist object");
  std::cout<<"pointer: "<<dynamicObject1<<"\n"; // pointer: [pointing to <adres>]
  dynamicObject1->Print();			// Printing object named "Frist object".
  {
    UniquePointer<const Object> dynamicObject2 = dynamicObject1;
    std::cout<<"pointer in braces: "<<dynamicObject1<<"   "<<dynamicObject2<<"\n"; // pointer in braces: [pointing to 0]   [pointing to <adres>]
    dynamicObject2->Print();	// Printing object named "Frist object".

    UniquePointer<const Object> dynamicObject3 = new Object ("Different object");
    cout<<dynamicObject3<<"\n";	// [pointing to <adres>]
    PrintObject(dynamicObject3); // Printing object named "Different object".

    dynamicObject3 = dynamicObject2 = dynamicObject2;
    cout<<"EQUAL: "<<"\t"<<dynamicObject1<<"\t"<<dynamicObject2<<"\t"<<dynamicObject3<<"\n"; // EQUAL: 	[pointing to 0]	[pointing to 0]	[pointing to <adres>]
    (*dynamicObject3).Print();	// Printing object named "Frist object".
  }

  return 0;
}
/*
===== INT =====
pointer: [pointing to <adres>]
value: 4
pointer in braces: [pointing to 0]   [pointing to <adres>]
value in braces: 4
pointer: [pointing to <adres>]   value: 6
Add two: 8
EQUAL: 	[pointing to 0]	[pointing to 0]	[pointing to <adres>]
value dynamicInt3: 4
===== OBJECT =====
pointer: [pointing to <adres>]
Printing object named "Frist object".
pointer in braces: [pointing to 0]   [pointing to <adres>]
Printing object named "Frist object".
[pointing to <adres>]
Printing object named "Different object".
EQUAL: 	[pointing to 0]	[pointing to 0]	[pointing to <adres>]
Printing object named "Frist object".
 */
