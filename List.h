#pragma once
#include "Primitives.h"
#define DEBUG 1
#define NEXT_STAGE 1

using namespace std;

class List {
	friend ostream& operator<<(ostream&, const List&);
	friend istream& operator>>(istream&, List&);
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
#endif
private:
	Object** elems;
	int capacity;
	int size;
}; // end class List
