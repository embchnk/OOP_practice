#ifndef MALENSTWO_SAMO_SPRZATACZ_H
#define MALENSTWO_SAMO_SPRZATACZ_H
#include "Malenstwo.h"

class Malenstwo;

class MalenstwoSamoSprzatacz{
public:
	MalenstwoSamoSprzatacz(Malenstwo* pointer)
		: _ptr (pointer)
	{}
	~MalenstwoSamoSprzatacz() {
		_ptr -> free();
	}

	Malenstwo* operator->() { return _ptr; }

private:
	Malenstwo* _ptr;
};

#endif // MALENSTWO_SAMO_SPRZATACZ_H
