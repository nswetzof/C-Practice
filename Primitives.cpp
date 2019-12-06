#include <iostream>
#include "Primitives.h"
#define TEMPLATE 0

#if TEMPLATE == 1
template<typename T>
std::ostream& operator<<(std::ostream& output, const T& obj) {
	output << obj.getVal();
	return output;
} // end function operator<<

#elif !TEMPLATE
std::ostream& operator<<(std::ostream& output, Object* obj) {
	obj->getOutput(output);
	return output;
} // end function operator<<
#endif

ostream& CharObject::getOutput(ostream& output) {
	//output << getVal();
	return output << getVal();
} // end CharObject function getOutput

#define cpp 1
#if cpp == 1
char CharObject::getVal() const {
	return value;
} // end CharObject function getVal
#endif