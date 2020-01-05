#pragma once
#include "Primitives.h"
#define DEBUG 0
#define NEXT_STAGE 1

using namespace std;

class List {
	friend ostream& operator<<(ostream&, const List&);
	friend istream& operator>>(istream&, List&);
	friend const int len(const List&);
public:
	List(); // default constructor
	List(const int);
	List(const List&); // copy constructor
	~List();
	Object* operator[](const int&) const;
	Object* &operator[](const int&);
	List& operator=(const List&);

	void append(Object*);
	Object* pop();
#if NEXT_STAGE // don't compile beyond this point unless NEXT_STAGE is defined
	void remove(Object* obj);
	template<typename T> void remove(T val) {
		int index = -1;
		for (int i = 0; i < size; i++) {
			if (*(elems[i]) == val) {
				index = i;
				break;
			}
		} // end for
		if (index != -1) {
			if (size < capacity / 4) {
				capacity /= 2;
			} // end inner if
			Object** new_list = new Object * [capacity]; // new_list will hold value of elems with element removed
			copy(elems, elems + index, new_list);
			copy(elems + index + 1, elems + size, new_list + index);
			size--;

			//elems = new Object * [capacity];
			elems = new_list;
			//copy(new_list, new_list + size, elems);
		} // end outer if
	}
	void sort_list();
#endif
private:
	Object** elems;
	int capacity;
	int size;
}; // end class List
