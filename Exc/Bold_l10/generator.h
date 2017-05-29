#ifndef generator_h
#define generator_h

template <typename T>
class generator {
public:
	generator(T var, T (*foo)(T))
		: _variable (var)
		, _foo (foo)
	{}
	generator& operator++() {
		_variable = _foo(_variable);
		return *this;
	}
	T current() const {
		return _variable;
	}
	void reset(T var, T (*foo)(T)) {
		_variable = var;
		_foo = foo;
	}
	void reset() {
		_variable = 'a';
	}
	bool operator>(T to_compare) {
		return _variable > to_compare;
	}
	bool operator<(T to_compare) {
		return _variable < to_compare;
	}
	T next() {
		++(*this);
		return _variable;
	}
private:
	T _variable;
	T (*_foo)(T);
};

#endif // generator_h