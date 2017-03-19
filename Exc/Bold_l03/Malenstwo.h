#ifndef Malenstwo_h
#define Malenstwo_h
#include <iostream>
//#include "MalenstwoSamoSprzatacz.h"

class MalenstwoSamoSprzatacz;

class Malenstwo {
public:
	Malenstwo();
	Malenstwo(int val)
		: _val (val)
	{
		std::cout << "Malenstwo(int) " << _val << std::endl; 
	}
	~Malenstwo() {
		//if (!safetyCounter) {
			std::cout << "Destruktor Malenstwo, counter: " << counter << std::endl;
			if (counter > 1) {
				counter--;
			}
			else {
				std::cout << "Ostatni obiekt na stercie, dealokuje skladowisko" << std::endl;
				counter--;
				flag = 0;
				::operator delete(ptr);
				ptr = 0;
			}
		//}
		safetyCounter = 0;
	}

	int& wartosc() { return *(&_val); }

	void* operator new(std::size_t size) {
		std::cout << "Alokuje 1" << std::endl;
		//std::cout << "Counter: " << counter << std::endl;
		if (!flag) {
			std::cout << "Pierwszy obiekt na stercie - prealokuje skladowisko na 100 elementow" << std::endl;
			flag = 1;
			counter++;
			ptr = ::operator new (size * 100);
			//std::cout << "Zaalokowana tablica: " << ptr << std::endl;
			Malenstwo* pointer = (Malenstwo*)ptr;
			//std::cout << "Użyto operatora new, zwrócony pointer to: " << pointer << std::endl;
			return pointer;
		}
		return ptr + (counter++ * size);
	}

	void operator delete(void* pointer) {
		Malenstwo* temp = (Malenstwo*)pointer;
		//temp -> ~Malenstwo();
		// if (counter > 1) {
		// 	counter--;
		// }
		// else {
		// 	std::cout << "Ostatni obiekt na stercie, dealokuje skladowisko" << std::endl;
		// 	counter = 0;
		// 	flag = 0;
		// 	::operator delete(ptr);
		// 	ptr = 0;
		// }
	}
	Malenstwo* retPtr() { return this; }

	void* operator+(int toMove) {
		return ptr + (4 * toMove);
	}

	void operator++() { _val++; }

	static int counter;
	static bool flag;
	static void* ptr;
	//flaga dająca znać czy destruktor został już użyty
	//na użytek klasy MalenstwoSamoSprzatacz
	static bool safetyCounter;

private:
	int _val;
};

class MalenstwoSamoSprzatacz{
public:
	MalenstwoSamoSprzatacz(Malenstwo* pointer)
		: _ptr (pointer)
	{
		/*ustawienie flagi na 1, destruktor obiektu
		  Malenstwo przestawi go na 0, jeśli zostanie 
		wywołany
		*/
		_ptr -> safetyCounter = 1;
		//std::cout << "Adres MalenstwoSamoSprzatacz: " << _ptr << std::endl;
	}
	~MalenstwoSamoSprzatacz() {
		std::cout << "Destruktor sprzatacz" << std::endl;
		/*jeśli destruktor obiektu Malenstwo z jakiegoś
		  powodu nie został wywołany, obiekt klasy
		  MalenstwoSamoSprzatacz uruchomi go we własnym
		  destruktorze, nie działa to dobrze, ale w zadaniu
		  spełnia swoją rolę (jest jeden obiekt typu 
		  MalenstwoSamoSprzatacz)
		*/
		if(_ptr -> safetyCounter) {
			//std::cout << "Weszło w if" << std::endl;
			_ptr -> safetyCounter = 0;
			_ptr -> ~Malenstwo();	
		}
	}

	Malenstwo* operator->() { return _ptr; }

private:
	Malenstwo* _ptr;
};

#endif // Malenstwo_h
