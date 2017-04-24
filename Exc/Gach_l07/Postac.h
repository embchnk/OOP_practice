#ifndef POSTAC_H
#define POSTAC_H
#include <iostream>
#include <sstream>

class Postac {
public:
	Postac(const int age)
		: _age (age)
	{}
	virtual ~Postac() {}

	virtual void print(std::ostream& out) const {
		out << "Postac ma " << _age << " lat.";
	}

	friend std::ostream& operator<<(std::ostream& out, const Postac& object) {
		object.print(out);

		return out;
	}
protected:
	int _age;
};

class Kobieta: public Postac {
public:
	Kobieta(const int age)
		: Postac(age)
	{}

	void print(std::ostream& out) const {
		out << "Kobieta w wieku " << _age << " lat.";
	}
};

class Mezczyzna: public Postac {
public:
	Mezczyzna(const int age)
		: Postac(age)
	{}

	void print(std::ostream& out) const {
		out << "Wiek mezczyzny to " << _age << " lat.";
	}
};

class Leela: public Kobieta {
public:
	Leela(const int age)
		: Kobieta(age)
	{}

	void print(std::ostream& out) const {
		out << "Leela " << _age << ".";
	}
};

class Fry: public Mezczyzna {
public:
	Fry(const int age)
		: Mezczyzna(age)
	{}

	void print(std::ostream& out) const {
		out << "Fry " << _age << ".";
	}
};


#endif // POSTAC_H
