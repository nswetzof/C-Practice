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
	return obj.equals(other);
} // end function operator==

bool Object::equals(Object& obj) {
#if DEBUG == 1
	cout << "\nIn object block\n";
	cout << "this: " << this->type() << endl;
	cout << "obj: " << obj->type() << endl;
#endif
	return this == &obj;
} // end function equals

bool Object::lt(Object& obj) {
	throw exception("Not implemented.");
} // end function lt

bool Object::gt(Object& obj) {
	throw exception("Not implemented.");
} // end function gt

bool operator<(Object& obj, Object& other) {
	return obj.lt(other);
} // end function operator<

bool operator>(Object& obj, Object& other) {
	return obj.gt(other);
} // end function operator>

bool operator<=(Object& obj, Object& other) {
	return (obj.lt(other) || obj.equals(other));
} // end function operator<=

bool operator>=(Object& obj, Object& other) {
	return (obj.gt(other) || obj.equals(other));
} // end function operator>=

Object& Object::operator=(Object& other) {
	cout << "\n\ncalling = " << typeid(*this).name() << "\n";
	Object* new_obj = this->setObject(other);
	return *this;
} // end function operator=

#if IMPLEMENT_SETOBJECT >= 1
Object* Object::setObject(Object& other) {
	cout << "\nCalling setObject for " << typeid(*this).name() << endl;
	throw exception("Not implemented.");
} // end function setObject
#endif

std::istream& IntObject::getInput(istream& input) {
	input >> value;
	return input;
} // end function getInput

IntObject& IntObject::operator=(int val) {
	value = val;
	return *this;
} // end function operator=(int)

bool operator==(Object& obj, int num) {
	Object* other = new IntObject(num);
	return (obj == *other);
} // end function operator==

bool operator==(Object& obj, char c) {
	Object* other = new CharObject(c);
	return (obj == *other);
} // end function operator==

bool IntObject::equals(Object& obj) {
	if(type() == obj.type())
		return getVal() == dynamic_cast<IntObject&>(obj).getVal();
	return false;
} // end function equals

bool IntObject::lt(Object& obj) {
	if (type() == obj.type()) {
		return value < dynamic_cast<IntObject&>(obj).getVal();
	} // end if
	throw logic_error("Unorderable types.");
} // end function lt

bool IntObject::gt(Object& obj) {
	if (type() == obj.type())
		return value > dynamic_cast<IntObject&>(obj).getVal();
	throw logic_error("Unorderable types.");
} // end function gt

Object* IntObject::setObject(Object& other) {
	cout << "\nCalling setObject for IntObject" << endl;
	if (typeid(other) == typeid(*this)) {
		return new IntObject(value);
		//IntObject(dynamic_cast<IntObject&>(other));
		//dynamic_cast<IntObject*>(this);
	}
	throw runtime_error("Object type mismatch.");
} // end function setObject

ostream& CharObject::getOutput(ostream& output) {
	output << getVal();
	return output;
} // end CharObject function getOutput

// could make this a void called setInput and do the same thing; no need for return value (same with IntObject)
istream& CharObject::getInput(istream& input) {
	input.get(value);
	return input;
} // end function getInput

bool CharObject::equals(Object& obj) {
	if (type() == obj.type())
		return getVal() == dynamic_cast<CharObject&>(obj).getVal();
	return false;
} // end function equals

bool CharObject::lt(Object& obj) {
	if (type() == obj.type()) {
		return value < dynamic_cast<CharObject&>(obj).getVal();
	} // end if
	throw logic_error("Unorderable types.");
} // end function lt

bool CharObject::gt(Object& obj) {
	if (type() == obj.type())
		return value > dynamic_cast<CharObject&>(obj).getVal();
	throw logic_error("Unorderable types.");
} // end function gt

char CharObject::getVal() const {
	return value;
} // end CharObject function getVal
