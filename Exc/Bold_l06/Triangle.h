#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"

class Triangle: public Shape {
public:
	Triangle(int size)
		: Shape(size)
	{}
	void Draw() const ;
};

#endif // TRIANGLE_H
