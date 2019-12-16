#include <iostream>
#include "Primitives.h"

std::ostream& operator<<(std::ostream& output, Object* obj) {
	try {
		obj->getOutput(output);
	}
	catch (exception& ex) {

	}
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

bool Object::operator==(Object& obj) const {
#define DEBUG 1
#if DEBUG == 1
	cout << "In object block\n";
#endif
	return this == &obj;
} // end function operator==

bool Object::equals(Object* obj) {
#if DEBUG == 1
	cout << "\nIn object block\n";
	cout << "this: " << this->type() << endl;
	cout << "obj: " << obj->type() << endl;
#endif
	return this == obj;
} // end function equals

std::istream& IntObject::getInput(istream& input) {
	input >> value;
	return input;
} // end function getInput

#if PTR
IntObject* IntObject::operator=(int val) {
	IntObject obj = IntObject(val);
	*this = obj;
	return this;
} // end function operator=(int)
#else
IntObject& IntObject::operator=(int val) {
	value = val;
	return *this;
} // end function operator=(int)
#endif

bool IntObject::operator==(IntObject& obj) const {
	return getVal() == obj.getVal();
} // end function operator==

bool IntObject::equals(IntObject* obj) {
	return getVal() == obj->getVal();
} // end function equals

ostream& CharObject::getOutput(ostream& output) {
	output << getVal();
	return output;
} // end CharObject function getOutput

// could make this a void called setInput and do the same thing; no need for return value (same with IntObject)
istream& CharObject::getInput(istream& input) {
	input.get(value);
	return input;
} // end function getInput

bool CharObject::operator==(CharObject& obj) const {
	return getVal() == obj.getVal();
} // end function operator==

bool CharObject::equals(CharObject* obj) {
	cout << "getVal() = " << getVal() << ",\tobj.getVal() = " << obj->getVal() << endl;
	return getVal() == obj->getVal();
} // end function equals

char CharObject::getVal() const {
	return value;
} // end CharObject function getVal

void* CharObject::getValPtr() {
	return &value;
} // end function getValPtr
