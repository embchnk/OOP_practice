#ifndef Line_h
#define Line_h


class FitResult {
public:
	~FitResult() {}
	virtual unsigned int nParams() const =0;
	virtual const char* expression() const =0;
	virtual const char* parameterName(int index) const =0;
	virtual float parameterValue(int index) const =0;
};

class Fit: public FitResult {
public:
	Fit(const char* name)
		: _name (name)
	{}
	~Fit() {}
	void print() const {
		std::cout << "This is " << _name << std::endl;
	}
	void appendPoint(float x, float y) {}
	void appendPoint(float noMatter, float noMatter2) const { std::cout << "Cannot add point (" << noMatter << ", " << noMatter2 << "), to const object." << std::endl; }
	FitResult& result() { 
		return *this;
	}
private:
	const char* _name;
};
#endif //Line_h