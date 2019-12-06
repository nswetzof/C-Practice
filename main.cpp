#include <iostream>
#include <vector>
#include "Primitives.h"

using namespace std;

#define BASIC 1

int main() {
	IntObject t0(2);
	CharObject t1('a');
	IntObject* ptr = &t0;

	vector<Object*> t(2);
	t[0] = &t0;
	t[1] = &t1;

	for (int i = 0; i < t.size(); i++) {
		cout.width(10);
		cout << t[i];
	}
} // end main