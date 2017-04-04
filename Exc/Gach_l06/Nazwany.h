// tego pliku NIE wolno modyfikowc

#pragma once

#include "NazwanyBaza.h"
#include <iostream>
#include <string>

class Nazwany : public NazwanyBaza {
public:
  Nazwany(std::string nazwa) : NazwanyBaza(nazwa) {}
  void Wypisz() const { std::cout << "To jest urzadzenie mechaniczne.\n"; }
};
