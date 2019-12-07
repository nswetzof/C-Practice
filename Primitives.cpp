#include <iostream>
#include "Primitives.h"

std::ostream& operator<<(std::ostream& output, Object* obj) {
	obj->getOutput(output);
	return output;
} // end function operator<<

ostream& CharObject::getOutput(ostream& output) {
	output << getVal();
	return output;
} // end CharObject function getOutput

#define cpp 1
#if cpp == 1
char CharObject::getVal() const {
	return value;
} // end CharObject function getVal
#endif