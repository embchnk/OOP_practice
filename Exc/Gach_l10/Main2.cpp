// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze napisac kod obliczajacy wyrazy ciagu Fibonaciego na etapie
// kompilacji. Wzor na wyrazy ciagu Fibonaciego jest nastepujacy:
// F(n) = F(n-1) + F(n-2)
// F(1) = 1
// F(2) = 1

// UWAGA!  
// Jezeli obliczenia nie beda wykonane na etapie kompilacji
// rozwiazanie zostanie ocenione na 0 punktow.

// UWAGA!
// Aby sprawdzic czy obliczenia wykonywane sa na etapie kompilacji
// można odkomentować linię #define ERROR. Po jej uruchomieniu powinny
// pojawic sie 3 błędy kompilacji o nastepujacej tresci:
// error: aggregate ‘ERR_MSG<13> msg1’ has incomplete type and cannot be defined
// gdzie argument szablonu ERR_MSG, to wyraz ciagu Fibonaciego.

// Prosze rowniez zaimplementowac klase bedaca tablica wyrazow ciagu
// Fibonaciego.

// Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie Lab11. Program nalezy kompilowac z flagami -Wall -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Pliku Lab11.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod). Powinien działać dla dowolnej
// liczby przekształceń.

// Zadanie nalezy rozwiazac samodzielnie, a przy jego wykonaniu nie
// wolno korzystać z internetu, notatek, ani żadnych innych materiałów
// (w tym własnych wcześniej przygotowanych plików).

// Skonczone zadanie nalezy wyslac uruchamiajac skrypt 
// ~gach/WyslijZadanie.sh
// bedac w katalogu zawierajacym rozwiazanie czyli ~/oop/lab_11


#include"Lab11.h"
#include<iostream>

// #define ERROR

template<int x> struct ERR_MSG;

int main ()
{
  std::cout<<"Values\n";
  std::cout<<"Fibonaci (7) = "<<Fibonaci<7>::value<<"\n";
  std::cout<<"Fibonaci (8) = "<<Fibonaci<8>::value<<"\n";
  std::cout<<"Fibonaci (9) = "<<Fibonaci<9>::value<<"\n";

#ifdef ERROR
  ERR_MSG<Fibonaci<7>::value> msg1;
  ERR_MSG<Fibonaci<8>::value> msg2;
  ERR_MSG<Fibonaci<9>::value> msg3;
#endif


  Array fibArray;
  fibArray.push_back(new Fibonaci<1>);
  fibArray.push_back(new Fibonaci<2>);
  fibArray.push_back(new Fibonaci<3>);
  Fibonaci<4>* fib4 = new Fibonaci<4>;
  fibArray.push_back(fib4);
  Fibonaci<5>* fib5 = new Fibonaci<5>;
  fibArray.push_back(fib5);

  std::cout<<"Array\n";
  fibArray.print();

  std::cout<<"add fib4: "<<fib4<<"\t"<<fibArray[3]<<"\n";
  std::cout<<"add fib5: "<<fib5<<"\t"<<fibArray[4]<<"\n";

  std::cout<<"Print\n";
  fib4->print();
  fibArray[3]->print();
  fib5->print();
  fibArray[4]->print();

  return 0;
}
/*
Values
Fibonaci (7) = 13
Fibonaci (8) = 21
Fibonaci (9) = 34
Array
Fibonaci(1) = 1
Fibonaci(2) = 1
Fibonaci(3) = 2
Fibonaci(4) = 3
Fibonaci(5) = 5
add fib4: <adres_fib4>  <adres_fib4>
add fib5: <adres_fib5>  <adres_fib5>
Print
Fibonaci(4) = 3
Fibonaci(4) = 3
Fibonaci(5) = 5
Fibonaci(5) = 5
*/