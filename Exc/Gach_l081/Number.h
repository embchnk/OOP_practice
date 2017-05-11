#ifndef NUMBER_H
#define NUMBER_H
#include <string>
#include <iostream>
#include <vector>

class Number {
public:
	Number(std::string, float);
	~Number() {
		std::cout << "Destroying number " << _value << std::endl;
	}
	static Number* Factory(std::string, float);
	static void SetRange(int, int);
	void Print() const;

	static int bottom;
	static int top;
	static std::vector <Number*> pointers;
private:
	std::string _name;
	float _value;
};

#endif // NUMBER_H
