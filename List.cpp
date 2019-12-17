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


List::~List() {
	delete[] elems;
} // end List destructor

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
	} // end if

	elems[size++] = obj_ptr;
} // end function append

Object* List::pop() {
	// check if list is empty
	if (size == 0) {
		throw out_of_range("List is empty.");
	}

	Object* last_elem = elems[--size]; // return value
	// if List is less than 1/4 full, halve the List's size
	if (size <= capacity / 4) {
		List list(*this);
		capacity > 1 ? capacity / 2 : 1;
		elems = new Object * [capacity]; // resize the list
		copy(list.elems, list.elems + size - 1, elems);
		//delete[] list.elems;
	}
	//size--;

	return last_elem;
} // end function pop

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

const int len(const List& l) {
	return l.size;
} // end function len

#if NEXT_STAGE
void List::remove(Object* obj) {
#if DEBUG
	cout << "Removing " << obj << " from " << *this << endl;
#endif
	int index = -1;
	for (int i = 0; i < size; i++) {
#if DEBUG
		cout << "elems[i]: " << elems[i]->type() << ",\tobj: " << obj->type() << endl;
		cout << "\t\t" << elems[i] << " == " << obj << ": " << (*elems[i] == *obj ? "true" : "false") << endl;

#endif
		if (*(elems[i]) == *obj) {
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
} // end function remove
#endif