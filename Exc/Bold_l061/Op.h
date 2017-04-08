#ifndef OP_H
#define OP_H

class Fun;
class Liniowa;

class Op1 {
public:
	Op1(double step)
		: h(step)
		, _ptr(Liniowa::utworz() -> a(1) -> b(0.))
	{}
	virtual ~Op1() {}
	Op1* z(Fun* fun) {
		_ptr = fun;
		return this;
	}
	virtual double w(double point) {
		return (_ptr -> wartosc(point + h) - _ptr -> wartosc(point - h)) / (2 * h);
	}
protected:
	double h;
	Fun* _ptr;
};

#endif // OP_H
