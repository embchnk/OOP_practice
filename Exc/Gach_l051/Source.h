#ifndef SOURCE_H
#define SOURCE_H
#include <string>

class Source {
public:
	Source(const char* sign)
		: _sign (sign)
	{}
	std::string _sign;
};

class OdtwarzaczDVD: public Source {
public:
	OdtwarzaczDVD()
		: Source("D")
	{}
};

class Komputer: public Source {
public:
	Komputer()
		: Source("K")
	{}	
};

#endif // SOURCE_H
