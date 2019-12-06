#include <exception>
#include "List.h"

using namespace std;

List::List() {
	elems = new Object[1];
} // end List default constructor

List::List(const int size) : SIZE(size) {
	elems = new Object[SIZE];
} // end List single-argument constructor

const Object* List::operator[](const int& index) {
	if (index >= SIZE)
		throw out_of_range("Index out of range.");
	return &elems[index];
} // end function operator[]