#include "Tablica.h"

Tablica::Tablica(int* table, int counter)
	: _table (new int [counter])
	, _counter (counter)
{
	for (int i = 0; i < _counter; ++i) 
		_table[i] = table[i];
}
/********************************************************/
std::ostream& operator<<(std::ostream& out, const Tablica& table) {
	for (int i = 0; i < table.retCounter(); ++i)
		out << table.retTable(i) << ", ";
	return out;
}
/********************************************************/
void copyTable(int* orginal, int* to_be_copy, int counter) {
	for (int i = 0; i < counter; ++i)
		to_be_copy[i] = orginal[i];
}
/********************************************************/
Tablica operator+(const Tablica table, int to_add) {
	Tablica* temp = new Tablica(table._table, table.retCounter());
	int temp_table[temp -> _counter];
	copyTable(temp -> _table, temp_table, temp -> _counter);
	temp -> _counter++;
	delete[] temp -> _table;
	temp -> _table = new int [temp -> _counter];
	copyTable(temp_table, temp -> _table, temp -> _counter - 1);
	temp -> _table[temp -> _counter - 1] = to_add;
	return *temp;
}
/********************************************************/
int& Tablica::operator()(int index) const {
	return _table[index];
}
/********************************************************/
Tablica Tablica::operator-(int to_delete) {
	int i = 0;
	int temp_table[_counter];
	while (_table[i] != to_delete && i < _counter)
		i++;
	if(i == _counter)
		return *this;
	copyTable(_table, temp_table, _counter);
	delete[] _table;
	_counter--;
	_table = new int [_counter];
	for (int j = 0; j < _counter; ++j) {
		if (j < i)
			_table[j] = temp_table[j];
		else
			_table[j] = temp_table[j + 1];

	}
	return *this;
}
/********************************************************/
Tablica Tablica::operator-=(int to_delete) {
	int i = 0;
	while (i < _counter) {
		i++;
		*this - to_delete;
	}
	return *this;
}
/********************************************************/
Tablica operator+(const Tablica f_table, const Tablica table) {
	int temp_table[f_table.retCounter() + table.retCounter()];
	for (int i = 0; i < f_table.retCounter(); ++i) {
		temp_table[i] = f_table.retTable(i);
	}
	for (int i = 0; i < table.retCounter(); ++i) {
		temp_table[i + f_table.retCounter()] = table.retTable(i);
	}
	Tablica* temp = new Tablica(temp_table, sizeof(temp_table) / sizeof(int));
	return *temp;
}
/********************************************************/
