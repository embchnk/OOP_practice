#ifndef Tablica_h
#define Tablica_h
#include <iostream>

class Tablica
{
public:
	class IteratorStaly {
	public:
		IteratorStaly(const Tablica* ptr, int index)
			: _ptr (ptr)
			, _index (index)
		{}

		int& operator*() { return _ptr -> _table[_index]; }
		void operator++() { _index++; }
		bool operator!=( IteratorStaly iter) {
			return (_index == iter._index )? 0 : 1;
		}
	private:
		const Tablica* _ptr;
		int _index;
	};

	Tablica() {}
	Tablica(int*, int);
	~Tablica() {}

	IteratorStaly koniec() const { return IteratorStaly(this, _counter); }
	IteratorStaly poczatek() const {return IteratorStaly(this, 0); }
	int retCounter() const { return _counter; }
	int retTable(int index) const { return _table[index]; }

	int& operator()(int) const;
	Tablica operator-(int);
	Tablica operator-=(int);

	friend Tablica operator+(const Tablica, const Tablica);
	friend Tablica operator+(const Tablica, int);
	friend std::ostream& operator<<(std::ostream&, const Tablica&);
	

private:
	int* _table;
	int _counter;
};

#endif // Tablica_h
