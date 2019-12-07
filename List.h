#pragma once
#include "Primitives.h"
//#define NEXT_STAGE

using namespace std;

class List {
	friend ostream& operator<<(ostream&, const List&);
	friend istream& operator>>(istream&, List&);
public:
	List(); // default constructor
	List(const int);
	List(const List&); // copy constructor
	Object* operator[](const int&) const;
	Object* &operator[](const int&);
	List& operator=(const List&);

	void append(Object*);
#ifdef NEXT_STAGE // don't compile beyond this point unless NEXT_STAGE is defined
#endif
private:
	Object** elems;
	int capacity;
	int size;
}; // end class List
