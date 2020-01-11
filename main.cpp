#include <iostream>
#include <fstream>
#include <assert.h>
#include <algorithm>
#include <iterator>
#include <vector> // for testing assignment operator
#include "Primitives.h"
#include "List.h"

using namespace std;

#define BASIC 1

int main() {
	ostream_iterator<Object> output(cout, " ");
	Int n1 = 40;
	Int n2 = 40;
	vector<Object*> test;
	test.push_back(&n1);
	test.push_back(&n2);
	Object* object_list = new Object[2];
	object_list[0] = (*test.at(0));
	object_list[1] = *test.at(1);
	cout << "\nobject_list[0] = " << &object_list[0] <<
		"\nobject_list[1] = " << &object_list[1] << endl;
	exit(0);

	Int t0(259783);
	cout << typeid(t0).name() << endl;
	Char t1('a');
	Int t2 = t0;
	PyInt ptr = &t0;
	Char t1a('a');
	PyObj t1_ptr = &t1;
	PyObj t2_ptr = &t1a;

	List list;
	list.append(&t0);
	list.append(&t1);
	list.append(new Int(522));
	list.append(new Char('c'));
	list.remove('a');
	cout << list << endl;
	Int::test();
	list.sort_list();
	cout << list << endl;
} // end main