#ifndef ROZNICZKOWANIE_H
#define ROZNICZKOWANIE_H
#include "Op.h"

class ProsteRozniczkowanie: public Op1 {
public:
	ProsteRozniczkowanie(double step)
		: Op1(step)
	{}
};


#endif // ROZNICZKOWANIE_H
