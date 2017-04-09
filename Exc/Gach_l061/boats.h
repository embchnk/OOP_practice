#ifndef Statek_h
#define StatekS_h
#include <string>

class Statek {
public:
	void UstawNazwe(std::string name) {
		_name = name;
	}
	void UstawWypornosc(int value) {
		_displacement = value;
	}
	void WypiszInformacje() const {
		std::cout << "nazwa: " << _name << "\n"
		<< "wypornosc: " << _displacement << std::endl;
		this -> writeInfo();
	}
	virtual void writeInfo() const =0;
protected:
	std::string _name;
	int _displacement;
};
// Virtual inheritance, rescuing from Diamond of Death!!
class StatekSilnikowy: public virtual Statek {
public:
	StatekSilnikowy()
		: Statek()
	{}
	void UstawPoziomOleju(double value) {
		_oil_level = value;
	}
	void WypiszPoziomOleju() const {
		std::cout << "Poziom oleju wynosi " << _oil_level << std::endl;
	}
	virtual void writeInfo() const {
		std::cout << "olej: " << _oil_level << std::endl;
	}
protected:
	double _oil_level;
};
// same as above
class Zaglowiec: public virtual Statek {
public:
	Zaglowiec()
		: Statek()
		, _sails_status(0)
	{}
	void ZagleStaw() { _sails_status = 1; }
	void ZaglePrecz() { _sails_status = 0; }
	void WypiszStanZagli() const {
		std::cout << "Zagle sa ";
		if (_sails_status)
			std::cout << "postawione" << std::endl;
		else
			std::cout << "zlozone" << std::endl;
	}
	virtual void writeInfo() const {
		std::cout << "zagle: ";
		if (_sails_status)
			std::cout << "postawione" << std::endl;
		else
			std::cout << "zlozone" << std::endl;
	}
protected:
	bool _sails_status;
};

class LodzPodwodna: public StatekSilnikowy {
public:
	LodzPodwodna()
		: StatekSilnikowy()
	{}
	void UstawMaksymalneZanurzenie(int value) {
		_max_depth = value;
	}
	void writeInfo() const {
		std::cout << "olej: " << _oil_level << std::endl;
		std::cout << "zanurzenie: " << _max_depth << std::endl;
	}
private:
	int _max_depth;
};

class Motorowka: public StatekSilnikowy {
public:
	Motorowka()
		: StatekSilnikowy()
	{}
	void UstawIloscPasazerow(int value) {
		_pass_amount = value;
	}
	void writeInfo() const {
		std::cout << "olej: " << _oil_level << std::endl;
		std::cout << "pasazerowie: " << _pass_amount << std::endl;
	}
private:
	int _pass_amount;
};

class Szkuner: public Zaglowiec {
public:
	Szkuner()
		: Zaglowiec()
	{}
};

class Kliper: public Zaglowiec {
public:
	Kliper()
		: Zaglowiec()
	{}
};

class Jacht: public Zaglowiec, public StatekSilnikowy {
public:
	Jacht()
		: Zaglowiec()
		, StatekSilnikowy()
	{}
	using Zaglowiec::UstawNazwe;
	using Zaglowiec::UstawWypornosc;
	void writeInfo() const {
		Zaglowiec::writeInfo();
		StatekSilnikowy::writeInfo();
	}
};

#endif // Statek_h
