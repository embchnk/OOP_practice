#ifndef vehicle_h
#define vehicle_h
#include "Nazwany.h"
#include <string>

class Pojazd: public Nazwany {
public:
	Pojazd(std::string name, int max_speed)
		: Nazwany(name)
		, _max_speed (max_speed)
	{}
	void WypiszPredkoscMaksymalna() const {
		std::cout << "Predkosc maksymalna tego pojazdu wynosi " << _max_speed << "km/h" << std::endl;
	}
protected:
	int _max_speed;
};

class Spalinowy {
public:
	Spalinowy(float oil_level)
		: _oil_level (oil_level)
	{}
	void WypiszPoziomOleju() const {
		std::cout << "Poziom oleju wynosi " << _oil_level << "." << std::endl;
	}
protected:
	float _oil_level;
};

class Narzedzie: public Nazwany {
public:
	Narzedzie(std::string name, std::string application)
		: Nazwany(name)
		, _application (application)
	{}
	void WypiszZastosowanie() const {
		std::cout << "Tego narzedzia uzywa sie do " << _application << std::endl;
	}
protected:
	std::string _application;
};

class Reczny {
public:
	Reczny(std::string power_source)
		: _power_source (power_source)
	{}
	void WypiszZrodloNapedu() const {
		std::cout << "Do napedzania tego urzadzenia uzywa sie " << _power_source << std::endl;
	}
protected:
	std::string _power_source;
};

class Samochod: public Pojazd, public Spalinowy {
public:
	Samochod(std::string name, int max_speed, float oil_level)
		: Pojazd(name, max_speed)
		, Spalinowy(oil_level)
	{}
	void Wypisz() const {
		std::cout << "To jest moje " << _name << std::endl;
		WypiszPredkoscMaksymalna();
		WypiszPoziomOleju();
	}
};

class Rower: public Pojazd, public Reczny {
public:
	Rower(std::string name, int max_speed, std::string power_source)
		: Pojazd(name, max_speed)
		, Reczny(power_source)
	{}
	void Wypisz() const {
		std::cout << "Wypisuje rower " << _name << std::endl;
		WypiszPredkoscMaksymalna();
		WypiszZrodloNapedu();
	}
};

class PilaSpalinowa: public Narzedzie, public Spalinowy {
public:
	PilaSpalinowa(std::string name, std::string application, float oil_level)
		: Narzedzie(name, application)
		, Spalinowy(oil_level)
	{}
	void Wypisz() const {
		std::cout << "Pila spalinowa marki " << _name << std::endl;
		WypiszZastosowanie();
		WypiszPoziomOleju();
	}
};

class Srubokret: public Narzedzie, public Reczny {
public:
	Srubokret(std::string name, std::string application, std::string power_source)
		: Narzedzie(name, application)
		, Reczny(power_source)
	{}
	void Wypisz() const {
		std::cout << "Srubokret typu " << _name << std::endl;
		WypiszZastosowanie();
		WypiszZrodloNapedu();
	}
};

#endif // vehicle_h
