#ifndef Tablica_h
#define Tablica_h
#include <iostream>


class Tablica
{
public:
	class Iterator {
	public:
		Iterator(Tablica* ptr, int index)
			: _ptr (ptr)
			, _index (index)
	{}

	Tablica* retPtr() const { return _ptr; }
	int retIndx() const { return _index; }

	int& operator*() { return _ptr -> _table[_index]; }
	void operator++() { _index++; }
	bool operator!=( Iterator iter) {
		return (_index == iter._index )? 0 : 1;
	}
	private:
		Tablica* _ptr;
		int _index;
	};

	class IteratorStaly {
	public:
		IteratorStaly(Iterator iter)
			: _ptr (iter.retPtr())
			, _index (iter.retIndx())
		{}
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

	Tablica tylkoPierwszeWystapienia();
	Iterator koniec() { return Iterator(this, _counter - 1); }
	Iterator poczatek() {return Iterator(this, 0); }
	IteratorStaly koniec() const { return IteratorStaly(this, _counter - 1); }
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
