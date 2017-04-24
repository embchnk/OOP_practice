#ifndef MAIN_H
#define MAIN_H
#include <exception>
#include <iostream>

class MyException: public std::exception {
public:
	MyException() {}
	virtual short type() =0;
};

class typ1: public MyException {
public:
	typ1() {}
	virtual ~typ1() {}
	virtual short type() {
		return 1;
	}
	virtual void PrzedstawSie() {
		std::cout << "Nazywam sie 1" << std::endl;
	}
};

class typ2: public MyException {
public:
	typ2() {}
	virtual ~typ2() {}
	virtual short type() {
		return 2;
	}
	virtual void PrzedstawSie() {
		std::cout << "Nazywam sie 2" << std::endl;
	}
};

class typ3: public MyException {
public:
	typ3() {}
	virtual ~typ3() {}
	virtual short type() {
		return 3;
	}
	virtual void PrzedstawSie() {
		std::cout << "Nazywam sie 3" << std::endl;
	}
};

class typ4: public MyException {
public:
	typ4() {}
	virtual ~typ4() {}
	virtual short type() {
		return 4;
	}
	virtual void PrzedstawSie() {
		std::cout << "Nazywam sie 4" << std::endl;
	}
};

class ObiektMiotajacy {
public:
	void Rzuc() {
		throw new typ2();
	}
};

void Przetworz1(MyException* my_exception) {
	std::cout << "wyjatek typu " << my_exception -> type() << " o adresie: " << my_exception << std::endl;
	delete my_exception;

	throw new typ4();
}

#endif // MAIN_H
