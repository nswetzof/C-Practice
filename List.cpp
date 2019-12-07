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

Object* List::operator[](const int& index) const {
	if (index >= size)
		throw out_of_range("Index out of range.");
	return elems[index];
} // end const function operator[]

Object*& List::operator[](const int& index) {
	if (index >= size)
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

ostream& operator<<(ostream& output, const List& l) {
	output << "[ ";
	for (int i = 0; i < l.size; i++) {
		//if (i % 12 == 0 && i > 0)
		//	output << '\n';
		output << l[i] << ' ';
	} // end for
	output << "]";

	return output;
} // end function operator<<

#define NEXT_STAGE 0
#if NEXT_STAGE
istream& operator>>(istream& input, List& l) {
	cout << "Enter list items" << endl;
	for (int i = 0; i < l.size; i++) {
		input >> dynamic_cast<IntObject*>(l[i]); // won't work; don't know why dynamic_cast doesn't bandaide the problem
	}
} // end function operator>>
#endif