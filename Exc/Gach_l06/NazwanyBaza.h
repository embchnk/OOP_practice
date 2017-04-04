#ifndef nazwany_baza_h
#define nazwany_baza_h

class NazwanyBaza {
public:
	NazwanyBaza(std::string name)
		: _name (name)
	{}
	virtual void Wypisz() const =0;
protected:
	std::string _name;
};

#endif // nazwany_baza_h
