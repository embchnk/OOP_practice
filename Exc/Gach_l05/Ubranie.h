#ifndef Ubranie_h
#define Ubranie_h
#include <string>
#include <iostream>
#include "Zelazko.h"

class Ubranie {
public:
	Ubranie(int value, std::string name)
		: _iron_status (1)
		, _value (value)
		, _name (name)
	{}
	void Prasuj(Zelazko& zelazko) {
		_iron_status = 0;
		std::cout << "Prasuje " << _name << " żelazkiem o temp. " << zelazko.retTemp() << std::endl;
	}
	void WypiszWlasciwosci() {
		std::cout << _name << " cena: " << _value << ". Stan ubrania: ";
		if (_iron_status) 
			std::cout << "pogniecione.\n";
		else
			std::cout << "wyprasowane.\n";
	} 
	virtual void Pogniec() =0;
protected:
	bool _iron_status;
	int _value;
	std::string _name;
};

class Koszula: public Ubranie {
public:
	Koszula(int value, std::string name)
		: Ubranie(value, name)
		, _iron_special_status (1)
	{}
	virtual void PrasujRekawy(Zelazko&) =0;
	void Pogniec() {
		_iron_status = 1;
		_iron_special_status = 1;
	}
	void WypiszWlasciwosci() {
		std::cout << _name << " cena: " << _value << ". Stan ubrania: ";
		if (_iron_status) 
			std::cout << "pogniecione. ";
		else
			std::cout << "wyprasowane. ";
		std::cout << "Stan rekawow: ";
		if (_iron_special_status)
			std::cout << "pogniecione.\n";
		else
			std::cout << "wyprasowane.\n";
	}
protected:
	bool _iron_special_status;
};

class Spodnie: public Ubranie {
public:
	Spodnie(int value, std::string name)
		: Ubranie(value, name)
		, _iron_special_status (1)
	{}
	virtual void PrasujNogawki(Zelazko&) =0;
	void Pogniec() {
		_iron_status = 1;
		_iron_special_status = 1;
	}
	void WypiszWlasciwosci() {
		std::cout << _name << " cena: " << _value << ". Stan ubrania: ";
		if (_iron_status) 
			std::cout << "pogniecione.\n";
		else
			std::cout << "wyprasowane.\n";
		std::cout << "Stan nogawek: ";
		if (_iron_special_status)
			std::cout << "pogniecione.\n";
		else
			std::cout << "wyprasowane.\n";
	}
protected:
	bool _iron_special_status;
};

class KoszulaBawelniana: public Koszula {
public:
	KoszulaBawelniana(const float value)
		: Koszula(value, "Koszula bawelniana")
	{}
	KoszulaBawelniana(const int value)
		: Koszula(value, "Koszula bawelniana")
	{}
	void PrasujRekawy(Zelazko& zelazko) {
		std::cout << "Prasuje rekawy" << std::endl;
	}
};

class KoszulaJedwabna: public Koszula {
public:
	KoszulaJedwabna(const float value)
		: Koszula(value, "Koszula jedwabna")
	{}
	KoszulaJedwabna(const int value)
		: Koszula(value, "Koszula jedwabna")
	{}
	void PrasujRekawy(Zelazko& zelazko) {
		std::cout << "Prasuje rekawy" << std::endl;
	}
};

class SpodnieBawelniane: public Spodnie {
public:
	SpodnieBawelniane(const float value)
		: Spodnie(value, "Spodnie bawelniane")
	{}
	SpodnieBawelniane(const int value)
		: Spodnie(value, "Spodnie bawelniane")
	{}
	void PrasujNogawki(Zelazko& zelazko) {
		std::cout << "Prasuje nogawki" << std::endl;
	}
};

class SpodnieJedwabne: public Spodnie {
public:
	SpodnieJedwabne(const float value)
		: Spodnie(value, "Spodnie jedwabne")
	{}
	SpodnieJedwabne(const int value)
		: Spodnie(value, "Spodnie bawelniane")
	{}
	void PrasujNogawki(Zelazko& zelazko) {
		std::cout << "Prasuje nogawki" << std::endl;
	}
};

#endif // Ubranie_h
