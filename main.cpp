#include <iostream>
#include <fstream>
#include "Primitives.h"
#include "List.h"

using namespace std;

#define BASIC 1

int main() {
	IntObject t0(2);
	CharObject t1('a');
	IntObject t2 = t0;
	IntObject* ptr = &t0;

	List list;
	list.append(&t0);
	list.append(&t1);
	list.append(new IntObject(522));
	list.append(new CharObject('c'));
	for (int i = 0; i < 100; i++)
		list.append(new IntObject(i));
	fstream os;
	os.open("test.dat", ios::out);
	os << list << endl;
} // end main