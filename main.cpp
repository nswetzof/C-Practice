#include <iostream>
#include <vector>
#include "Primitives.h"

using namespace std;

#define BASIC 1

int main() {
	IntObject test(2);
	IntObject t1 = test;
	cout << &test << "      " << &t1 << endl;
	exit(0);

	//vector<Object*> t(2);
	//t[0] = &test;
	//t[1] = &t1;

	//for (int i = 0; i < t.size(); i++) {
	//	cout.width(10);
	//	cout << t[i];
	//}
} // end main