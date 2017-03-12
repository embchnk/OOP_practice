// Nazwa pliku wykonywalnego: Complex

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze zaimplementowac mozliwosc uzywania w kodzie angielskiego i
// polskiego zapisu liczb dziesietnych, tzn. przy uzyciu kropki lub
// przecinka jako separatora miejsc dziesietnych. Ta implementacja
// moze zakladac, ze cyfra na miesjscu dziesietnym jest rozna od zera.

// Prosze napisac klase ComplexNumber reprezentujaca liczbe zespolona,
// wraz z wykorzystywanymi w tym programie operatorami.

// Prszoe zadbac o dobre zarzadzanie pamiecia.

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

  const float numEnglish_1 = ((english)1.2);
  const float numPolish_1 = ((polish)2,3);
  const float numEnglish_2 = (english)1.342;
  const float numPolish_2 = ((polish)2,789);
  cout<<numEnglish_1<<" "<<numPolish_1<<" "<<numEnglish_2<<" "<<numPolish_2<<"\n";

  ComplexNumber staticFirst (1, 2);
  cout<<staticFirst<<"\n";

  {
    ComplexNumber staticTmp (2, 3);
    ComplexNumber* dynamicTmp1 = new ComplexNumber (10, 11);

    cout<<staticTmp<<" "<<*dynamicTmp1<<"\n";
  } 

  ComplexNumber staticSecond (4, 5);
  ComplexNumber* dynamicSecond = new ComplexNumber (12, 13);
  new ComplexNumber (14, 15);

  cout<<staticSecond<<" "<<*dynamicSecond<<"\n";

  delete dynamicSecond;

  cout<<staticFirst<<" "<<staticSecond<<"\n";

  return 0;
}
/*
1.2 2.3 1.342 2.789
Constructing 1+2i
1+2i
Constructing 2+3i
Constructing 10+11i
2+3i 10+11i
Deleting: 2+3i
Constructing 4+5i
Constructing 12+13i
Constructing 14+15i
4+5i 12+13i
Deleting: 12+13i
1+2i 4+5i
Deleting: 4+5i
Deleting: 1+2i
Deleting: 10+11i
Deleting: 14+15i
*/
