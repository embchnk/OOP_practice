#pragma once
#include <vector>
#include "registration.H"


template<class Base>
struct Generator {
  virtual ~Generator() {}
  virtual Base* obj() const { return 0; };
  virtual int id() const { return 0; };
};

template<class Base, class T> //, int ID>
struct TGenerator : public Generator<Base
				     > {
  virtual T* obj() const { return new T; };
  virtual int id() const { return type2int<T>::value; };  
};


#define TYPE(B, T) TGenerator<B, T>()

template<class T>
class Factory {
public:
  template<class G>
  void preload( G );
  T* produce( int id );
  ~Factory();
private:
  std::vector<Generator<T>*> m_ids;
};

template<class T>
template<class G>
void Factory<T>::preload( G ) {
  m_ids.push_back(new G);
}

template<class T>
T* Factory<T>::produce( int id ) {
  for ( size_t i = 0; i < m_ids.size(); ++i ) {    
    if ( m_ids[i]->id() == id) {
      return m_ids[i]->obj();
    }
  }
  return 0;
}


template<class T>
Factory<T>::~Factory() {
  for ( size_t i = 0; i < m_ids.size(); ++i ) {    
    delete m_ids[i];
  }

}