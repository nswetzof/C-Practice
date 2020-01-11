#pragma once
#include <iostream>
#include <exception>
#define PTR 0
#define TEST 1
#define TEMPLATE 1
#define IMPLEMENT_SETOBJECT 1

using namespace std;
//typedef IntObject Int;
//typedef CharObject Char;

class Object {
	friend ostream& operator<<(ostream&, Object*);
	friend istream& operator>>(istream&, Object*);
	friend bool operator==(Object&, Object&);
	friend bool operator<(Object&, Object&);
	friend bool operator>(Object&, Object&);
	friend bool operator<=(Object&, Object&);
	friend bool operator>=(Object&, Object&);

	friend bool operator==(Object&, int);
	friend bool operator==(Object&, char);
public:
	virtual ostream& getOutput(ostream& output) { output << "Object at " << this; return output; }
	virtual istream& getInput(istream&) { throw exception("Not implemented."); }

	//virtual bool operator==(Object&);
	Object& operator=(Object&);
	virtual Object* setObject(Object&) = 0;
#if TEST
	virtual bool equals(Object&);
	virtual bool lt(Object&);
	//virtual bool ltObject(Object*);
	virtual bool gt(Object&);
#endif
}; // end class Object

class IntObject : public Object {
	friend bool operator==(Object&, int);
public:
	static void test() {
		cout << "this is a test";
	}
	IntObject() : value(0) {} // end IntObject default constructor
	IntObject(int val) :
		value(val) {
	} // end IntObject constructor with 1 parameter // end IntObject single-argument constructor

	virtual ostream& getOutput(ostream& os) {
		os << getVal();
		return os;
	}
	virtual istream& getInput(istream&);
	
	virtual Object* setObject(Object&);

	IntObject& operator=(IntObject& i_obj) {
		cout << "Calling assignment operator for two IntObjects" << endl;
		value = i_obj.getVal();
		return *this;
	}
	
#if TEST
	virtual bool equals(Object&);
	virtual bool lt(Object&);
	//virtual bool ltObject(Object*);
	virtual bool gt(Object&);
#endif

#if !PTR // not using pointer implementation
	IntObject& operator=(int);
#else // using pointer implementation
	IntObject* operator=(int);
#endif
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

	virtual Object* setObject(Object&);

#if TEST
	virtual bool equals(Object&);
	virtual bool lt(Object&);
	//virtual bool ltObject(Object*);
	virtual bool gt(Object&);
#endif
	char getVal() const;
private:
	char value;
}; // end class CharObject

typedef Object* PyObj;
typedef IntObject Int;
typedef CharObject Char;
typedef IntObject* PyInt;
typedef CharObject* PyChar;