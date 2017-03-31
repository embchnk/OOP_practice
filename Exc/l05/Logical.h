#ifndef Logical_h
#define Logical_h

//Wyjaśnienie:
/*Klasy OneArgClass i TwoArgClass są klasami bazowymi ponieważ
  dla każdej z klas dziedziczących potrzebujemy jednej metody,
  zwracającej wartość logiczną danego wyrażenia i w zależności
  od tego po której dziedziczymy będzie to albo wyrażenie o
  jednym argumencie albo o dwóch.
  Dziedziczenie po klasie Logical, byłoby według mnie nieefektywne,
  ponieważ musielibyśmy zadeklarować dwie metody o liczbie
  argumentów 1 lub 2, a w sposób w jaki to rozwiązałem działanie
  i liczbę argumentów definiuje klasa bazowa
*/


//Klasa bazowa dla klas przyjmujących jedną wartość logiczną
class OneArgClass {
public:
	//Metoda zwracająca wartość logiczną wyrażenia
	virtual bool ret_val(bool) const =0;
};


//Klasa bazowa dla klas przyjmujących dwie wartości logiczne
class TwoArgClass {
public:
	//Metoda zwracająca wartość logiczną wyrażenia
	virtual bool ret_val(bool, bool) const =0;
};

//Klasy pochodne:
class OR: public TwoArgClass {
public:
	OR(): TwoArgClass() {}
	bool ret_val(bool log_1, bool log_2) const {
		return (log_1 || log_2);
	}
};

class AND: public TwoArgClass {
public:
	AND(): TwoArgClass() {}
	bool ret_val(bool log_1, bool log_2) const {
		return (log_1 && log_2);
	}
};

class XOR: public TwoArgClass {
public:
	XOR(): TwoArgClass() {}
	bool ret_val(bool log_1, bool log_2) const {
		return (log_1 != log_2);
	}
};

class NOT: public OneArgClass {
public:
	NOT(): OneArgClass() {}
	bool ret_val(bool log) const {
		return (!log);
	}
};

class NOOP: public OneArgClass {
public:
	NOOP(): OneArgClass() {}
	bool ret_val(bool log) const {
		return (log);
	}
};

class Logical {
public:
	//Metoda zwracająca wartość logiczną dla danych argumentów
	static bool eval(const TwoArgClass& log, bool val_1, bool val_2) {
		return log.ret_val(val_1, val_2);
	}
	//Metoda zwracająca wartość logiczną dla danego argumentu logicznego
	static bool eval(const OneArgClass& log, bool val) {
		return log.ret_val(val);
	}
};



#endif //Logical_h