#ifndef MOVE_H
#define MOVE_H


class MoveRight {
public:
	MoveRight(int how_much)
		: _how_much (how_much)
	{}

	void operator()(Shape& shape) {
		shape.f_x += _how_much;
	}
private:
	int _how_much;
};

class MoveDown {
public:
	MoveDown(int how_much)
		: _how_much (how_much)
	{}

	void operator()(Shape& shape) {
		shape.f_y -= _how_much;
	}
private:
	int _how_much;
};

class MoveUp {
public:
	MoveUp(int how_much)
		: _how_much (how_much)
	{}

	void operator()(Shape& shape) {
		shape.f_y += _how_much;
	}
private:
	int _how_much;
};

class Program {
public:
	void process(Shape& shape) const {
		(*move_right_ptr)(shape);
		shape.Draw();
		(*move_down_ptr)(shape);
		shape.Draw();
		(*move_up_ptr)(shape);
		shape.Draw();
	}	
	~Program() {
		delete move_right_ptr;
		delete move_down_ptr;
		delete move_up_ptr;
	}
	void move_right(int how_much) {
		move_right_ptr = new MoveRight(how_much);
	}
	void move_down(int how_much) {
		move_down_ptr = new MoveDown(how_much);
	}
	void move_up(int how_much) {
		move_up_ptr = new MoveUp(how_much);
	}
private:
	MoveDown* move_down_ptr;
	MoveRight* move_right_ptr;
	MoveUp* move_up_ptr;
};

#endif // MOVE_H
