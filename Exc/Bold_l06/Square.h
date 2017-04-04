#ifndef SQUARE_H
#define SQUARE_H
#include "Shape.h"

class Square: public Shape {
public:
	Square(int size)
		: Shape(size)
	{}
	void Draw() const;
};

#endif // SQUARE_H
