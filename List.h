#pragma once
#include "Primitives.h"
//#define NEXT_STAGE

using namespace std;

class List {
	friend ostream& operator<<(ostream&, List&);
public:
	List(); // default constructor
	List(const int);
	List(const List&); // copy constructor
	const Object* operator[](const int&);
	List& operator=(const List&);

	void append(Object*);
	void print() const;
#ifdef NEXT_STAGE // don't compile beyond this point unless NEXT_STAGE is defined
#endif
private:
	Object** elems; // TODO: Make private after debugging
	int capacity;
	int size;
}; // end class List
