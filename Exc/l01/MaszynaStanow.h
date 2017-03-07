#ifndef MaszunaStanow_h 
#define	MaszynaStanow_h
#include "Stan.h"

class Stan;

class MaszynaStanow
{
	Stan * _ptr;

	static Stan * actStan;
public:
	void start() const;
	MaszynaStanow();

	MaszynaStanow operator+=( Stan * );
	Stan operator()();
	MaszynaStanow operator++();
	friend std::ostream & operator<<( std::ostream& , MaszynaStanow& );
	friend std::ostream & operator<<( std::ostream& , const MaszynaStanow& );
	MaszynaStanow operator--();
};




#endif //MaszynaStanow_h