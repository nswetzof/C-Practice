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
	Int t0 = 2;
	Int t1 = 1;
	List l;
	l.append(&t0);
	l.append(&t1);
	l.append(new Int(-1));
	l.sort_list();
} // end main