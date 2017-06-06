#ifndef Verifier_h
#define Verifier_h
#include <iostream>
#include <string>
#include <sstream>
#define SECURED(data) ArgVerificationFailed::name = data; try {
#define ENDSECURED } catch(const ArgVerificationFailed& e ) { Verifier::handle(); }

// funkcja do konkatenacji napisu z liczba
std::string concat(const char*, int);

// klasa wyrzucana jako wyjatek
class ArgVerificationFailed {
public:
	ArgVerificationFailed() {}
	// konstruktor nadajacy odpowiednie wartosci
	ArgVerificationFailed(int, std::string);
	friend std::ostream& operator<<(std::ostream&, const ArgVerificationFailed&);
	virtual const char* what() const throw () {
		return "ArgVerificationFailed";
	}
	static int arg;
	static std::string status;
	static std::string name;
};

// klasa obslugujaca wyrzucony wyjatek
class Verifier {
public:
	// metody porównujące :
	static void le(int arg1, int arg2) {
		if (!(arg2 <= arg1)) {
			throw ArgVerificationFailed(arg2, concat("has to be lower than or equal", arg1));
		}
	}
	static void gt(int arg1, int arg2) {
		if (!(arg2 > arg1))
			throw ArgVerificationFailed(arg2, concat("has to be higher than", arg1));
	}
	static void ge(int arg1, int arg2) {}
	static void lt(int arg1, int arg2) {}
	// 
	// metoda obslugujaca rezucony wyjatek
	static void handle() {
		try {
			throw ArgVerificationFailed();
		}
		catch (const ArgVerificationFailed& e) {
			std::cout << e.what();
			if (e.name != " ")
				std::cout << " in " << e.name << " Argument " << e.arg << " " << e.status << std::endl;
			else
				std::cout << " Argument " << e.arg << " " << e.status << std::endl;
		}
	}
	/*static int arg;
	static std::string status;
	static std::string name;*/
};


#endif //Verifier_h