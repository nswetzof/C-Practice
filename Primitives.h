#pragma once
#include <iostream>
#include <exception>
#define PTR 0
#define TEST 1
#define TEMPLATE 1

using namespace std;
//typedef IntObject Int;
//typedef CharObject Char;

class Object {
	friend ostream& operator<<(ostream&, Object*);
	friend istream& operator>>(istream&, Object*);
	friend bool operator==(Object&, Object&);
public:
	virtual ostream& getOutput(ostream& output) { output << "Object at " << this; return output; }
	virtual istream& getInput(istream&) { throw exception("Not implemented."); }
	
	//virtual bool operator==(Object&);
#if TEST
	virtual bool equals(Object*);
	virtual void* getValPtr() = 0;
	virtual string type() { return "Object"; }
	virtual void convert(void*) = 0;
#endif
protected:
	void* value_ptr = NULL;
private:
}; // end class Object

class IntObject : public Object {
public:
	IntObject() : value(0) { value_ptr = static_cast<int*>(&value); } // end IntObject default constructor
	IntObject(int val) :
		value(val) {
		value_ptr = static_cast<int*>(&value);
	} // end IntObject constructor with 1 parameter // end IntObject single-argument constructor

	virtual ostream& getOutput(ostream& os) {
		os << getVal();
		return os;
	}
	virtual istream& getInput(istream&);
	
	virtual IntObject& operator=(IntObject& i_obj) {
		value = i_obj.getVal();
		return *this;
	}
	
	virtual void convert(void* val_ptr);

#if TEST
	virtual bool equals(Object*);
	virtual string type() { return "Int"; }
#endif

#if !PTR // not using pointer implementation
	IntObject& operator=(int);
#else // using pointer implementation
	IntObject* operator=(int);
#endif
	int getVal() const {
		return value;
	} // end function getVal

	virtual void* getValPtr() {
		return &value;
	} // end function getVal

	
private:
	int value;
}; // end class IntegerObject

class CharObject : public Object {
public:
	CharObject() : value('0') { value_ptr = static_cast<char*>(&value); } // default constructor
	CharObject(char val) : value(val) {
		value_ptr = static_cast<char*>(&value);
	} // single argument constructor
	virtual ostream& getOutput(ostream&);
	virtual istream& getInput(istream&);

	virtual void convert(void* val_ptr);
#if TEST
	virtual bool equals(Object*);
	virtual string type() { return "Char"; }
#endif
	char getVal() const;
	virtual void* getValPtr();
private:
	char value;
}; // end class CharObject

typedef Object* PyObj;
typedef IntObject Int;
typedef CharObject Char;
typedef IntObject* PyInt;
typedef CharObject* PyChar;