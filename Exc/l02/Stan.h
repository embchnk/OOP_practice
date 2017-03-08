#ifndef Stan_h
#define Stan_h

class Stan{
public:
	//konstruktor
	Stan();
	//konstruktor przepisujący łańcuch znaków przekazany w argumencie do tablicy _stan
	//alokuje potrzebne miejsce
	Stan( const char* );
	//destruktor
	~Stan();
	//metoda zwracająca tablicę znaków, do użytku przez metody z klasy MaszynaStanow
	char* stan(){ return _stan; }

	//operator wypisujący
	void operator()();


private:
	char* _stan;

};



#endif //Stan_h
