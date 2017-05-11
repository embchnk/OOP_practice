#ifndef LOKAJ_H
#define LOKAJ_H
#include "Pomieszczenie.h"

template <void (Pomieszczenie::*foo)(void) const>
void Lokaj(Pomieszczenie& room) {
	(room.*foo)();
}

template <void (Pomieszczenie::*foo)(void) const>
void Lokaj(const Pomieszczenie& room) {
	std::cout << "Pomieszczenie " << room.retName() << " jest zamkniete" << std::endl;
}

template <bool val>
void Lokaj(const Pomieszczenie& room) {
	std::cout << "Nic nie robie" << std::endl;
}

#endif // LOKAJ_H
