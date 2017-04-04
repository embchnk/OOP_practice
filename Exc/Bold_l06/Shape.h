#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>

typedef int pos_t;

class Shape {
public:
	Shape(int size) 
		: f_WIDTH(60)
		, f_HEIGHT(15)
		, f_y (0)
		, f_x (0)
		, f_size (size)
		, top_marigin (0)
	{}
	virtual void Draw() const =0;
	void SetPos(int x_coord, int y_coord) {
		f_x = x_coord;
		f_y = y_coord;
	}

	int f_WIDTH;
	int f_HEIGHT;
	int f_y;
	int f_x;
	int f_size;
	int top_marigin;
};

#endif // SHAPE_H
