#include <iostream>
#include "Primitives.h"

std::ostream& operator<<(std::ostream& output, Object* obj) {
	obj->getOutput(output);
	return output;
} // end function operator<<

istream& operator>>(istream& input, Object* obj) {
	obj->getInput(input);
	return input;
} // end function operator>>
//std::istream& operator>>(std::istream& input, IntObject* obj) {
//	obj->getInput(input);
//	return input;
//} // end function operator>>

std::istream& IntObject::getInput(istream& input) {
	input >> value;
	return input;
} // end function getInput

ostream& CharObject::getOutput(ostream& output) {
	output << getVal();
	return output;
} // end CharObject function getOutput

// could make this a void called setInput and do the same thing; no need for return value (same with IntObject)
istream& CharObject::getInput(istream& input) {
	input.get(value);
	return input;
} // end function getInput


char CharObject::getVal() const {
	return value;
} // end CharObject function getVal
