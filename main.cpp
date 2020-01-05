#include <iostream>
#include <fstream>
#include <assert.h>
#include "Primitives.h"
#include "List.h"

using namespace std;

#define BASIC 1

int main() {
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
	list.sort_list();
	cout << list << endl;
} // end main