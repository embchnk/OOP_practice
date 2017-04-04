// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze zaprojektowac hierarchie klas i zaimplementowac klasy
// potrzebne do wykonania kodu funkcji main. Projekt powinien byc
// taki, aby latwo mozna bylo dodac inne figury lub przeksztalcenia.

// W plikach Square.cpp i Triangle.cpp znajduja sie implementacje
// funkcji Draw, ktore nalezy wykorzystac.

// Pliku lab06.cpp nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod). 

// Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie Lab06. Program nalezy kompilowac z flagami -Wall -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Przy wykonaniu zadania nie wolno korzystać z internetu, notatek,
// ani żadnych innych materiałów (w tym własnych wcześniej
// przygotowanych plików)

// Kody źródłowe muszą znajdować się w katalogu ~/oop/lab_LABNR. Prawa
// do tego katalogu muszą być równe 700 (tylko dostęp dla
// właściciela).

// Skonczone zadanie nalezy wyslac uruchamiajac skrypt 
// /home/dokt/dog/WyslijZadanie.sh
// bedac w katalogu zawierajacym rozwiazanie czyli ~/oop/lab_06


#include"lab06.h"

int main ()
{
  Square square (10);
  square.SetPos(5, 8);
  square.Draw();
  
  MoveRight move_right (10);	// move object by 10 to the right
  move_right (square);		// transform the square 
  square.Draw();
  
  MoveDown move_down (4);
  move_down (square);
  square.Draw();

  Program move_around;		// prepare a set of transformations
  move_around.move_right(10);	// move object by 10 right
  move_around.move_down(5);	// move object by 5 down
  move_around.move_up(3);	// move object by 3 up
  move_around.process(square);	// execute prepared transformations on square

  Triangle triangle (5);
  triangle.SetPos(30, 3);
  triangle.Draw();
  move_around.process(triangle); // execute prepared transformations on triangle
}
/*
----------------------------------------------------------------------
     ##########
     ##########
     ##########
     ##########
     ##########
     ##########
     ##########
     ##########
     ##########
     ##########








----------------------------------------------------------------------
----------------------------------------------------------------------
               ##########
               ##########
               ##########
               ##########
               ##########
               ##########
               ##########
               ##########
               ##########
               ##########








----------------------------------------------------------------------
----------------------------------------------------------------------

               ##########
               ##########
               ##########
               ##########
               ##########
               ##########
               ##########
               ##########
               ##########
               ##########




----------------------------------------------------------------------
----------------------------------------------------------------------

                         ##########
                         ##########
                         ##########
                         ##########
                         ##########
                         ##########
                         ##########
                         ##########
                         ##########
                         ##########




----------------------------------------------------------------------
----------------------------------------------------------------------






                         ##########
                         ##########
                         ##########
                         ##########
                         ##########
                         ##########
                         ##########
                         ##########
                         ##########
                         ##########
----------------------------------------------------------------------
----------------------------------------------------------------------



                         ##########
                         ##########
                         ##########
                         ##########
                         ##########
                         ##########
                         ##########
                         ##########
                         ##########
                         ##########


----------------------------------------------------------------------
----------------------------------------------------------------------







                                   #      
                                  ###    
                                 #####  
                                #######
                               #########



----------------------------------------------------------------------
----------------------------------------------------------------------







                                             #      
                                            ###    
                                           #####  
                                          #######
                                         #########



----------------------------------------------------------------------
----------------------------------------------------------------------












                                             #      
                                            ###    
                                           #####  
                                          #######
                                         #########
----------------------------------------------------------------------
----------------------------------------------------------------------









                                             #      
                                            ###    
                                           #####  
                                          #######
                                         #########

----------------------------------------------------------------------
*/
