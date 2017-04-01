#ifndef SCREEN_H
#define SCREEN_H
#include "Source.h"
#include <iostream>

class Screen
{
public:
	Screen(int width, int height)
		: _width (width)
		, _height (height)
	{}
	virtual void Wyswietl(const Source& source) const =0;
	virtual void print_frame() const =0;
protected:
	int _width;
	int _height;
};

class Monitor: public Screen {
public:
	Monitor(int width, int height)
		: Screen(width, height)
	{}
	void Wyswietl(const Source& source) const {
		std::cout << "Polaczono monitor i ";
		if (source._sign == "K")
			std::cout << "komputer" << std::endl;
		else
			std::cout << "DVD" << std::endl;

		print_frame();

		for (int i = 0; i < _height; ++i) {
			for (int j = 0; j < _width; ++j)
				std::cout << source._sign;
			std::cout << std::endl;
		}

		print_frame();
	}

	 void print_frame() const {
	 	for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < _width; ++j)
				std::cout << "+";
			std::cout << std::endl;
		}
	 }
};

class Rzutnik: public Screen {
public:
	Rzutnik(int width, int height)
		: Screen (width, height)
	{}
	void Wyswietl(const Source& source) const {
		std::cout << "Polaczono rzutnik i ";
		if (source._sign == "K")
			std::cout << "komputer" << std::endl;
		else
			std::cout << "DVD" << std::endl;

		for (int i = 0; i < _height; ++i) {
			for (int j = 0; j < _width; ++j)
				std::cout << source._sign;
			std::cout << std::endl;
		}
	}

	void print_frame() const {}
};

class TelewizorLCD: public Screen {
public:
	TelewizorLCD(int width, int height)
		: Screen(width, height)
	{}
	void Wyswietl(const Source& source) const {
		std::cout << "Polaczono telewizor i ";
		if (source._sign == "K")
			std::cout << "komputer" << std::endl;
		else
			std::cout << "DVD" << std::endl;

		_which_one = 0;
		print_frame();

		for (int i = 0; i < _height; ++i) {
			for (int j = 0; j < _width; ++j)
				std::cout << source._sign;
			std::cout << std::endl;
		}

		_which_one = 1;
		print_frame();
	}

	void print_frame() const {
		if (!_which_one) {
			for (int j = 0; j < _width; ++j)
				std::cout << "*";
			std::cout << std::endl;
		}
		else {
			for (int j = 0; j <= _width / 2; ++j)
				std::cout << "* ";
			std::cout << std::endl;
			for (int j = 0; j < _width / 2; ++j)
				std::cout << " &";
			std::cout << std::endl;
			for (int j = 0; j <= _width / 2; ++j)
				std::cout << "* ";
			std::cout << std::endl;
		}
	}
private:
	mutable bool _which_one;
};

#endif // SCREEN_H
