#pragma once
#include "Primitives.h"

using namespace std;

class List {
public:
	List(); // default constructor
	List(const int);
	const Object* operator[](const int&);
	Object* elems; // TODO: Make private after debugging
private:
	int SIZE;
}; // end class List
