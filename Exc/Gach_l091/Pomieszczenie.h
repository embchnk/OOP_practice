#include <iostream>
#include <string>

class Pomieszczenie {
public:
	Pomieszczenie(std::string name)
		: _name (name)
	{}
	template <typename T>
	void wstaw(T value) {
		std::cout << "Wstawiam " << value << " do pomieszczenia: " << _name << std::endl;
	}
	void zetrzyj_kurze() const {
		std::cout << "Scieram kurze w pomieszczeniu: " << _name << std::endl;
	}
	void umyj_podloge() const {
		std::cout << "Myje podloge w pomieszczeniu: " << _name << std::endl;
	}
	void odkurz() const {
		std::cout << "Odkurzam pomieszczenie: " << _name << std::endl; 
	}

	std::string retName() const {
		return _name;
	}
	// static void zetrzyj_kurze() {}
	// static void umyj_podloge() {}
	// static void odkurz() {}

	// static void closed_room(const Pomieszczenie& room) {
	// 	std::cout << "Pomieszczenie " << room._name << " jest zamkniete" << std::endl;
	// }
private:
	std::string _name;
};