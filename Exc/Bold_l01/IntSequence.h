#ifndef IntSequence_h
#define IntSequence_h

class IntSequence
{
	int* _sequence;
	int _current;
	int _counter;

public:

	IntSequence();
	~IntSequence();
	bool finished() { return ( _current + 1 == _counter ); }
	void reset();


	friend int ReturnSizeOfTable( int* );

	IntSequence& operator<<( int );
	int operator()();
	int operator++( int );
	int operator--( int );
	void operator=( int& ) const;
	void* operator new( std::size_t );
	void* operator new[]( std::size_t );
	operator int() const;


};


#endif //IntSequence_h