#include <iostream>
#include <exception>

// myException class
class DivisionByZero: public std::exception {
	/* virtual
	   const char* - return type
	   const - this method can be even called on const instances of this class
	   throw() - means that this method will not yield any exception
	*/
	virtual const char* what() const throw () {
		return "Division by zero is not allowed!";
	}
};


// test function dividing two values
float division(float factor_one, float factor_two) {
	if (!factor_two)
		throw DivisionByZero();
	return factor_one / factor_two;
}

int main(void) {
	float a = 10;
	float b = 5;

	// here is dividing of proper values, function shouldn't throw an exception
	try {
		std::cout << division(a, b) << std::endl;
	}
	catch (std::exception& exc) {
		std::cout << exc.what() << std::endl;
	}

	a = 10;
	b = 0;

	// here is dividing by zero, function should throw an exception
	try {
		std::cout << division(a, b) << std::endl;
	}
	catch (std::exception& exc) {
		std::cout << exc.what() << std::endl;
	}
}
