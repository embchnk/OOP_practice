#ifndef Zelazko_h
#define Zelazko_h

class Zelazko {
public:
	Zelazko(int value, std::string brand)
		: _value (value)
		, _temp (0)
		, _brand (brand)
	{}
	int retTemp() { return _temp; }
	void UstawTemperature(int temp) {
		_temp = temp;
	}
	void WypiszWlasciwosci() {
		std::cout << _brand << " cena: " << _value << ". temperatura: " << _temp << std::endl;
	}
protected:
	int _value;
	int _temp;
	std::string _brand;
};

class ZelazkoZelmer: public Zelazko {
public:
	ZelazkoZelmer(int value)
		: Zelazko(value, "Zelmer")
	{}
};

class ZelazkoTefal: public Zelazko {
public:
	ZelazkoTefal(int value)
		: Zelazko(value, "Tefal")
	{}
};

#endif // Zelazko_h
