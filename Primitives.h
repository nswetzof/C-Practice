#pragma once
#include <iostream>

using namespace std;

class Object {
	friend ostream& operator<<(ostream&, Object*);
	friend istream& operator>>(istream&, Object*);
public:
	virtual ostream& getOutput(ostream&) = 0;
	virtual istream& getInput(istream&) = 0;
}; // end class Object

class IntObject : public Object {
public:
	IntObject() : value(0) {} // end IntObject default constructor
	IntObject(int val) :
		value(val) {} // end IntObject constructor with 1 parameter // end IntObject single-argument constructor

	virtual ostream& getOutput(ostream& os) {
		os << getVal();
		return os;
	}
	virtual istream& getInput(istream&);
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
	virtual istream& getInput(istream&);
	char getVal() const;
private:
	char value;
}; // end class CharObject