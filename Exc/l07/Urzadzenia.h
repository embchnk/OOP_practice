#ifndef Urzadzenia_h
#define Urzadzenia_h
#include <sstream>
#include <string>

/* Zastosowalem ponizsza heirarchie, ponieważ:
   - aby dynamic_cast w pierwszym przypadku zwrocil null_ptr 
     potrzebujemy aby klasa Skaner nie byla klasa pochodna od klasy
     papierozerne, gdyz wtedy zawieralaby w sobie kompletny obiekt
     klasy papierozerne i rzutowanie byloby mozliwe
   - klasa Drukarka dziedziczy po klasie Papierozerne wiec zawiera
     w sobie komplety obiekt tejze klasy dlatego dynamic_cast zwraca
     pointer != null_ptr
   - w reszcie przypadkow mamy miec zwrocony valid ptr wiec
     klasa Wielofunkcyjne musi zawierac w sobie kompletne 
     obiekty klas Skaner, Ksero i Drukarka, co oznacza ze powinna po nich
     dziedziczyc, dodatkowo musi byc mozliwe zrzutowanie pointera na 
     Wielofunkcyjne na pointer na Papierozerne dlatego musimy miec pewnosc
     ze klasa Wielofunkcyjne dziedziczy posrednio po klasie Papierozerne
*/

// klasa niepowiazana z reszta jesli chodzi o hierarchie
class Rozdzielczosc {
public:
	// konstruktor
	Rozdzielczosc(int width, int height)
		: _width (width)
		, _height (height)
	{}
	// wymiary
	int _width, _height;
};


// klasa bazowa dla kazdej kolejnej klasy
class Urzadzenie {
public:
	// konstruktor domyslny
	Urzadzenie()
		: _resolution(0, 0)
	{}
	// kontruktor przepisujacy wymiary
	Urzadzenie(const Rozdzielczosc& res)
		: _resolution (res._width, res._height)
	{}
	// wirutalny destruktor, zanim zadeklarowalem metode rodzaj byl mi potrzebny
	// aby zadeklarowac klase Urzadzenie jako wirtualna
	virtual ~Urzadzenie() {}
	// czysta metoda
	virtual std::string rodzaj() const =0;
protected:
	const Rozdzielczosc _resolution;
};

// klasa bazowa, dziedziczy wirtualnie po klasie Urzadzenie
class Papierozerne: virtual public Urzadzenie {
public:
	// domyslny konstruktor
	Papierozerne() {}
	// konstruktor przekazujacy argument do konstruktora klasy bazowej
	Papierozerne(const Rozdzielczosc& res)
		: Urzadzenie(res)
	{}
	// metoda zwracajaca rodzaj
	std::string rodzaj() const {
		return "Papierozerne";
	}
	// wirtualny destruktor
	virtual ~Papierozerne() {}
};

// klasa dziedziczaca po klasie Urzadzenie wirtualnie
class Skaner: virtual public Urzadzenie {
public:
	// konstruktor kopiujacy klase rozdzielczosc do elementu klasy
	Skaner(const Rozdzielczosc& res)
		: Urzadzenie()
		, _resolution(res)
	{}
	// metoda zwracajaca rodzaj
	std::string rodzaj() const {
		return "Skaner";
	}
	// metoda zwracajaca wymiary obiektu
	std::string rozdzielczosc() const;
protected:
	const Rozdzielczosc& _resolution;
};

// klasa dziedziczaca po Papierozerne oraz Urzadzenie (posrednio)
class Drukarka: virtual public Papierozerne {
public:
	// konstruktor kopiujacy klase rozdzielczosc do elementu klasy
	Drukarka(const Rozdzielczosc& res)
		: Papierozerne()
		, _resolution(res)
	{}
	// metoda zwracajaca rodzaj
	std::string rodzaj() const {
		return "Drukarka";
	}
	// metoda zwracajaca wymiary obiektu
	std::string rozdzielczosc() const;
protected:
	const Rozdzielczosc& _resolution;
};

class Ksero: virtual public Papierozerne {
public:
	// konstruktor domyslny, na potrzeby klasy dziedziczacej
	Ksero() {}
	// metoda zwracajaca rodzaj
	std::string rodzaj() const {
		return "Ksero";
	}
};

// klasa dziedziczaca po trzech klasach pochodnych od Urzadzenia oraz w dwoch przypadkach
// od papierozerne, glownie z jej powodu potrzebne jest dziedzczenie wirtualne
class Wielofunkcyjne: public Ksero, public Skaner, public Drukarka {
public:
	// konstruktor kopiujacy obie rozdzielczosci do dwoch roznych klas bazwoych
	Wielofunkcyjne(const Rozdzielczosc& res1, const Rozdzielczosc& res2)
		: Ksero()
		, Skaner(res2)
		, Drukarka(res1)
	{}
	// metoda zwracajaca rodzaj
	std::string rodzaj() const {
		return "Wielofunkcyjne";
	}
};


#endif // Urzadzenia_h