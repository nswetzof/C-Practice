#pragma once
#include <iostream>

using namespace std;

class Object {
	friend ostream& operator<<(ostream&, Object*);
public:
	Object() {}
	virtual ostream& getOutput(ostream& output) {
		throw runtime_error("Shouldn't appear here");
		return output;
	}
}; // end class Object

class IntObject : public Object {
public:
	IntObject() : value(0) {} // end IntObject default constructor
	IntObject(int val) :
		value(val) {} // end IntObject constructor with 1 parameter

	virtual ostream& getOutput(ostream& os) {
		os << getVal();
		return os;
	}

	virtual IntObject& operator=(IntObject& i_obj) {
		value = i_obj.getVal();
		return *this;
	}

	int getVal() const {
		return value;
	} // end function getVal
	
private:
	int value;
}; // end class IntegerObject

class CharObject : public Object {
public:
	CharObject() : value('0') {} // default constructor
	CharObject(char val) : value(val) {} // single argument constructor
	virtual ostream& getOutput(ostream&);
	char getVal() const;
private:
	char value;
}; // end class CharObject