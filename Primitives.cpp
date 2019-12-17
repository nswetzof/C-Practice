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



bool operator==(Object& obj, Object& other) {
	return (&obj)->equals(&other);
} // end function operator==

//bool Object::operator==(Object& obj) {
//#define DEBUG 1
//#if DEBUG == 1
//	cout << "In object block\n";
//#endif
//	convert(value_ptr);
//	Object* object = &obj;
//	object->convert(obj.value_ptr);
//	return true;
//	//return ( *(value_ptr) == *(object->value_ptr) );
//} // end function operator==

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

IntObject& IntObject::operator=(int val) {
	value = val;
	return *this;
} // end function operator=(int)

bool IntObject::equals(Object* obj) {
	return getVal() == dynamic_cast<IntObject*>(obj)->getVal();
} // end function equals

void IntObject::convert(void* val_ptr) {
	val_ptr = static_cast<int*> (val_ptr);
} // end function convert

ostream& CharObject::getOutput(ostream& output) {
	output << getVal();
	return output;
} // end CharObject function getOutput

// could make this a void called setInput and do the same thing; no need for return value (same with IntObject)
istream& CharObject::getInput(istream& input) {
	input.get(value);
	return input;
} // end function getInput

bool CharObject::equals(Object* obj) {
	cout << "getVal() = " << getVal() << ",\tobj.getVal() = " << dynamic_cast<CharObject*>(obj)->getVal() << endl;
	return getVal() == dynamic_cast<CharObject*>(obj)->getVal();
} // end function equals

void CharObject::convert(void* val_ptr) {
	val_ptr = static_cast<char*>(val_ptr);
} // end function convert

char CharObject::getVal() const {
	return value;
} // end CharObject function getVal

void* CharObject::getValPtr() {
	return &value;
} // end function getValPtr
