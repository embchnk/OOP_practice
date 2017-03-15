#ifndef BiVector_h
#define BiVector_h
#include <iostream>

class BiVector{
public:

	class const_iterator{
	public:
		int i;
		const_iterator( BiVector* );
		const_iterator( BiVector*, int );
		const_iterator& operator=( const_iterator );
		int operator*();
		const_iterator& operator++();
	
	private:
		BiVector* _ptr;
	};

	BiVector();
	~BiVector(){}
	BiVector& push_back( int );
	BiVector& push_front( int );
	const_iterator begin();
	const_iterator end();
	friend bool operator!=( const_iterator, const_iterator );

	
	int operator[]( int );

private:

	int _front[20];
	int _back[20];
	int _itrtr_f;
	int _itrtr_b;

};



#endif //BiVector_h
