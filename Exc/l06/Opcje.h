#ifndef Opcje_h
#define Opcje_h
#include <string>

/* 
   Powodem dla którego stosuję następującą hierarchię jest fakt, że
   klasy OpcjaBezArgumentowa i OpcjaArgumentowa mają wspólny element
   którym jest flaga oraz wspólne metody. Klasa Op nie potrzebuje według
   mnie innej klasy jako bazowej, gdyż jedyne jej "odwołanie" do innych klas
   to wywołanie konsturktora, do czego nie trzeba dziedziczenia, wystarczy 
   wcześniejsze zadeklarowanie tworzonej klasy	
*/
class Opcja {
public:
	// konstruktor, sprawdzający poprawność argumentu
	Opcja(std::string flag) {
		std::size_t found = flag.find("-");
		if (found != std::string::npos)
			_flag = flag;
		else
			_flag = "-" + flag;
	}
	// destruktor
	virtual ~Opcja() {}
	// metoda zwracająca elementy obiektu
	virtual std::string str() const =0;
	// metoda zwracająca typ obiektu
	virtual std::string typ() const =0;
	// metoda zwracająca wartość flagi danego obiektu
	virtual std::string nazwa() const =0;

protected:
	std::string _flag;
};

class OpcjaArgumentowa: public Opcja {
public:
	// konstruktor
	OpcjaArgumentowa(std::string flag, std::string argument)
		: Opcja(flag)
		, _argument(argument)
	{}
	std::string str() const {
		return _flag + " " + _argument;
	}
	std::string typ() const {
		return "OpcjaArgumentowa";
	}
	std::string nazwa() const {
		return _flag.substr(1, _flag.size());
	}
	// metoda zwracająca argument
	std::string arg() const {
		return _argument;
	}
private:
	std::string _argument;
};

class OpcjaBezArgumentowa: public Opcja {
public:
	// konstruktor
	OpcjaBezArgumentowa(std::string flag)
		: Opcja(flag)
	{}
	std::string str() const {
		return _flag;
	}
	std::string typ() const {
		return "OpcjaBezArgumentowa";
	}
	std::string nazwa() const {
		return _flag.substr(1, _flag.size());
	}
};

class Op {
public:
	// metoda tworząca odpowiedni obiekt w zależności od stringa 
	// przekazanego jako arugment
	static Opcja* dekoduj(std::string options) {
		std::size_t found = options.find(" ");
		if (found == std::string::npos)
			return new OpcjaBezArgumentowa(options);
		else
			return new OpcjaArgumentowa(options.substr(0, found), options.substr(found + 1, options.size()));

	}
	// metoda tworząca nowy obiekt
	static Opcja* Bezargumentowa(std::string name) {
		Opcja* ptr = new OpcjaBezArgumentowa(name);
		return ptr;
	}
};


#endif //Opcje_h