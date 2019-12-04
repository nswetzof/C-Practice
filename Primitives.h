#pragma once
#include <iostream>

using namespace std;

class Object {
	//virtual friend ostream& operator<<(ostream&, const Object&);
public:
	Object() {}
	//virtual int getVal() = 0;
	//virtual double getVal() = 0;
	//virtual Object operator=(Object&) = 0;
}; // end class Object

class IntObject : public Object {
	friend ostream& operator<<(ostream& output, const IntObject& i_obj);
public:
	IntObject() : value(0) {} // end IntObject default constructor
	IntObject(int val) :
		value(val) {} // end IntObject constructor with 1 parameter

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