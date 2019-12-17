#include <iostream>
#include <fstream>
#include <assert.h>
#include "Primitives.h"
#include "List.h"

using namespace std;

#define BASIC 1
#define tname(t, v) (static_cast<(t)*>((v))) // DOESN'T WORK

struct A {
	friend bool operator==(A& a1, A& a2) {
		return a1.equals(a2);
	}
	virtual bool equals(A& a) = 0;
};

struct B : A {
	B() : value(3) {}
	virtual bool equals(A& other) {
		return value == dynamic_cast<B&>(other).value;
	}
	int value;
};


int main() {
	Int t0(259783);
	Char t1('a');
	Int t2 = t0;
	PyInt ptr = &t0;
	Char t1a('a');
	PyObj t1_ptr = &t1;
	PyObj t2_ptr = &t1a;

	cout << "t1 == t1a: " << (*t1_ptr == *t2_ptr ? "true" : "false") << endl;
	//exit(1);

	List list;
	list.append(&t0);
	list.append(&t1);
	list.append(new Int(522));
	list.append(new Char('c'));
	Int test = 34;
	test = 45;
	list.append(&test);
	//for (int i = 0; i < 100; i++)
	//	list.append(new IntObject(i));
	fstream os;
	list.remove(&t1a);
	cout << list[2] << endl;
	cout << list << endl;
} // end main