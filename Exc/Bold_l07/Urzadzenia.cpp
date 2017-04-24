#include "Urzadzenia.h"

std::string Skaner::rozdzielczosc() const {
	std::stringstream oss;
	oss << _resolution._width << "x" << _resolution._height;
	return oss.str();
}
/**************************************************************/
std::string Drukarka::rozdzielczosc() const {
	std::stringstream oss;
	oss << _resolution._width << "x" << _resolution._height;
	return oss.str();
}
/**************************************************************/
