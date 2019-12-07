#include <iostream>
#include <vector>
#include "Primitives.h"
#include "List.h"

using namespace std;

#define BASIC 1

int main() {
	IntObject t0(2);
	CharObject t1('a');
	IntObject t2 = t0;
	IntObject* ptr = &t0;

	//vector<Object*> t(2);
	List list;
	list.append(&t0);
	list.append(&t1);
	list.append(&t2);
	list.print();
} // end main