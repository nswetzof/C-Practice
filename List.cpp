#include <exception>
#include "List.h"
#include <algorithm>
#include <iterator>

using namespace std;

List::List() : 
	capacity(0), size(0), elems(new Object*[0]) {} // end List default constructor

List::List(const int cap) : 
	size(0), capacity(cap), elems(new Object*[capacity]) {} // end List single-argument constructor

List::List(const List& list) {
	capacity = list.capacity;
	size = list.size;
	elems = new Object*[capacity];
	for (int i = 0; i < size; i++)
		elems[i] = list.elems[i];
} // end List copy constructor

const Object* List::operator[](const int& index) {
	if (index >= capacity)
		throw out_of_range("Index out of range.");
	return elems[index];
} // end function operator[]

List& List::operator=(const List& list) {
	List new_list(list);
	return new_list;
}

void List::append(Object* obj_ptr) {
	// if all elements are full, double the size of the List
	if (size == capacity) {
		List list(*this);
		capacity = capacity > 0 ? capacity * 2 : capacity + 1;
		elems = new Object*[capacity]; // resize the list
		copy(list.elems, list.elems + size, elems);
		delete[] list.elems;
	} // end if

	elems[size++] = obj_ptr;
} // end function append

void List::print() const {
	// print every element of the array
	ostream_iterator<Object*> output(cout, " ");
	cout << "[ ";
	copy(elems, elems + size, output);
	cout << "]";
} // end function print
#define NEXT_STAGE 0
#if NEXT_STAGE == 1
#endif