#ifndef LICZNIK_H
#define LICZNIK_H
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>

template <typename T>
class Licznik {
public:
	void dodaj(const char* string, const char* length) {
		for (unsigned int i = 0; i < strlen(string); ++i)
			++_map[string[i]];
	}
	void dodaj(const char character) {
		++_map[character];
	}
	int ilosc(const char character) {
		return _map[character];
	}
	void statystyka(std::ostream& out) {
		for (typename std::map<T, int>::iterator iter = _map.begin(); iter != _map.end(); ++iter)
			out << (*iter).first << " - " << (*iter).second << std::endl;
	}
	Licznik<T>& operator<<(std::string buffer) {
		++_map[buffer];
		return *this;
	}
	std::vector<T>& najczestsze(int amount) {
		std::vector< std::pair<int, T> > temp_vector;
		std::pair<int, T> temp;
		for (typename std::map<T, int>::iterator iter = _map.begin(); iter != _map.end(); ++iter) {
			temp.first = iter -> second;
			temp.second = iter -> first;
			temp_vector.push_back(temp);
		}
		std::sort(temp_vector.begin(), temp_vector.end());
		std::vector<T>* ptr = new std::vector<T>;
		for (int i = 0; i < amount; ++i)
			ptr -> push_back(temp_vector[temp_vector.size() - (i + 1)].second);
		return *ptr;
	}
	typedef T value_type;
private:
	std::map<T, int> _map;	
};

template <typename T>
void pvec(std::vector<T> vec, std::ostream& out) {
	for (unsigned int i = 0; i < vec.size(); ++i)
		out << vec[i] << " ";
	out << std::endl;
}

#endif // LICZNIK_H
