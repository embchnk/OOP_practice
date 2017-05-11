// Nazwa pliku wykonywalnego: Wyjatki

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze napisac klase Number, ktora bedzie przechowywac nazwe oraz
// wartosc. Klasa moze przechowywac jedynie wartosci z wczesniej
// ustawionego zakresu. Klasa ma glosne konstruktor i destruktor.

// Prosze zwrocic uwage na zarzadzanie pamiecia. Tak aby nie bylo
// wyciekow, ani podwojnego usuwania obiektow.

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

int main ()
{
  Number::SetRange(1, 6);
  
  try {
    Number* lowest = Number::Factory("lowest", 2.2); // Manufacturing number 2.2
    lowest->Print();				     // lowest = 2.2
    lowest->Print();				     // lowest = 2.2

    Number* middle = Number::Factory("middle", 5.4); // Manufacturing number 5.4
    middle->Print();				     // middle = 5.4

    Number* highest = Number::Factory("highest", 8.3); // Manufacturing number 8.3 \n Huston we've got problem
    highest->Print();

    std::cout<<"END OF NUMBERS"<<std::endl;
  }
  catch (const OutOfRange exception) {
    std::cout<<"Huston we've got problem"<<std::endl;
    std::cout<<exception<<std::endl; // Number named: highest has value 8.3 which is outside of the allowed range: [1, 6]
    std::cout<<"Cleaning up"<<std::endl;
  }

  std::cout<<"Good job, man!"<<std::endl;

}
/*
Manufacturing number 2.2
lowest = 2.2
lowest = 2.2
Manufacturing number 5.4
middle = 5.4
Manufacturing number 8.3
Huston we've got problem
Number named: highest has value 8.3 which is outside of the allowed range: [1, 6]
Cleaning up
Destroying number 2.2
Destroying number 5.4
Destroying number 8.3
Good job, man!
*/
