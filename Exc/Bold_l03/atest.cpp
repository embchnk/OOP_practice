/*
 * Czesta alokacja malych obiektow jest czesta przyczyna niewydajnosci programow.
 * W zadaniu mamy wlasnie z do czynienia z mala klasa. 
 * Nalezy do niej dodac alokatory tak aby wlasnie alokacja odbywala sie jednorazowo na poczatku programu 
 * a pozniejsze wytworzenia obiektow uzywal raz zaalokowanego wiekszego (na 100 el) obszaru pamieci.
 * Jedynym skladnikiem klasy Malenstwo ma byc pojedynczy integer.
 *
 * Druga pomocna klasa (acz trywialna klasa do napisania jest MalenstwoSamoSprzatacz) dostarczajaca semantyki wskaznika ale dbajacy o usuniecie pamieci przy wyjsciu z zakresu.
 *
 * Sompilowac do plitu atest z flagami -Wall -g
 */
 
#include <iostream>

#include "Malenstwo.h"

int main() {
  Malenstwo* x1 = new Malenstwo(12);
  std::cout << x1->wartosc() << std::endl;
  Malenstwo* x2 = new Malenstwo(13);
  Malenstwo* x3 = new Malenstwo(34);
  Malenstwo* x4 = new Malenstwo(7);
  //std::cout << x1 << " " << x2 << " " << x3 << " " << x4 << std::endl;
  std::cout << "cos o ulozeniu w pamieci" << std::endl;
  x3->wartosc() = 9;
  x4->wartosc() = 7;

  std::cout << "x3 " << (x3)->wartosc() << std::endl;
  std::cout << "x3++ " << (x3+1)->wartosc() << std::endl;

  std::cout << "a teraz bedziemy sprzatac" << std::endl;
  
  delete x1;
  delete x2;
  delete x4;
  delete x3;
  std::cout << "usuniete wszystkie obiekty" << std::endl;
  
  delete new Malenstwo(3);
  
  x1 = new Malenstwo(99); 
  {
    MalenstwoSamoSprzatacz sm(new Malenstwo(51));
    std::cout << "sm : " << sm->wartosc() << std::endl;
    sm->wartosc() ++;
    std::cout << "sm : " << sm->wartosc() << std::endl;
    //delete sm -> retPtr();
  }
  delete x1; 
}
/* wynik
Alokuje 1
Pierwszy obiekt na stercie - prealokuje skladowisko na 100 elementow
Malenstwo(int) 12
12
Alokuje 1
Malenstwo(int) 13
Alokuje 1
Malenstwo(int) 34
Alokuje 1
Malenstwo(int) 7
cos o ulozeniu w pamieci
x3 9
x3++ 7
a teraz bedziemy sprzatac
Ostatni obiekt na stercie, dealokuje skladowisko
usuniete wszystkie obiekty
Alokuje 1
Pierwszy obiekt na stercie - prealokuje skladowisko na 100 elementow
Malenstwo(int) 3
Ostatni obiekt na stercie, dealokuje skladowisko
Alokuje 1
Pierwszy obiekt na stercie - prealokuje skladowisko na 100 elementow
Malenstwo(int) 99
Alokuje 1
Malenstwo(int) 51
sm : 51
sm : 52
Ostatni obiekt na stercie, dealokuje skladowisko
 */
