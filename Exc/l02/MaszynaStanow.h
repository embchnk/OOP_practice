#ifndef MaszynaStanow_h
#define MaszynaStanow_h
#include "Stan.h"
#include <iostream>
#include <vector>

class Stan;

class MaszynaStanow{
public:
	//Konstruktor, ustawia _actStan na -1, oraz licznik _counter na 0
	//_actStan jest ustawiany na -1, ponieważ 0 oznaczałoby wskazywanie na pierwszy element
	MaszynaStanow();
	//Destruktor, usuwający wszystkie pointery w tablicy oraz zwalniający tablicę
	~MaszynaStanow();
	//Metoda ustawiająca _actStan na 0
	void start();
	
	//Operator zwracający bieżący sta
	Stan& operator()();
	//Operator zwiększający licznik _actStan o 1
	MaszynaStanow& operator++();
	//Operator zmniejszający licznik _actStan o 1
	MaszynaStanow& operator--();
	//Opertator przypisujący kolejnemu elementowi tablicy _stanTable wskaźnik przekazany jako argument
	MaszynaStanow& operator+=( Stan* );
	
	friend std::ostream& operator<<( std::ostream&, const MaszynaStanow& );


private:
	std::vector < Stan* > _stanTable;
	int _actStan;

};



#endif //MaszynaStanow_h
