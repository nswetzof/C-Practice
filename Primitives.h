#pragma once
#include <iostream>

using namespace std;

class Object {
	//virtual friend ostream& operator<<(ostream&, const Object&);
public:
	Object() {}
	virtual ostream& getOutput(ostream&) = 0;
	//virtual int getVal() const = 0;
	//virtual double getVal() const = 0;
	//virtual Object operator=(Object&) = 0;
}; // end class Object

class IntObject : public Object {
	friend ostream& operator<<(ostream& output, const IntObject* i_obj);
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

	virtual int getVal() const {
		return value;
	} // end function getVal
	
private:
	int value;
}; // end class IntegerObject