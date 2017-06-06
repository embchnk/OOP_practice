#ifndef LIST_H
#define LIST_H

template <typename T>
class node {
public:
	node(T var) 
		: _val (var)
		, _next (0)
	{}
	void defineNext(node<T>* ptr) {
		_next = ptr;
	}
	node<T>* returnNext() {
		return _next;
	}
	T returnVal() const {
		return _val;
	}
	~node() {
		delete _val;
		delete _next;
	}
private:
	T _val;
	node<T> *_next;

};

class agh {
public:
	template <typename T>
	class list {
	public:
		list()
			: _head (0)
			, _end (0)
		{}
		~list() {
			delete begin().returnPtr();
		}
		class iterator {
		public:
			iterator()
				: _iter (0)
			{}
			iterator(node<T>* ptr)
				: _iter (ptr)
			{}
			node<T>* returnPtr() const {
				return _iter;
			}
			iterator returnNext() const {
				return iterator(_iter -> returnNext());
			}
			bool operator!=(const iterator& iter) {
				return _iter != iter.returnPtr() -> returnNext();
			}
			iterator operator++() {
				_iter = _iter -> returnNext();
				return *this;
			}
			T operator*() {
				return returnPtr() -> returnVal();
			}
		private:
			node<T> *_iter;
		};
		void push_back(T var) {
			if (_end.returnPtr()) {
				node<T> *temp = _end.returnPtr();
				temp -> defineNext(new node<T>(var));
				_end = temp -> returnNext();
			}
			else {
				_head = iterator(new node<T>(var));
				_end = _head;
			}
		}
		void print() const {
			iterator temp = _head;
			while (temp.returnPtr() -> returnNext()) {
				std::cout << *(temp.returnPtr() -> returnVal()) << ", ";
				temp = temp.returnNext();
			}
			std::cout << *(temp.returnPtr() -> returnVal());
			std::cout << std::endl;
		}
		iterator end() {
			return _end;
		}
		iterator begin() {
			return _head;
		}
	private:
		iterator _head;
		iterator _end;
	};
};

#endif // LIST_H
