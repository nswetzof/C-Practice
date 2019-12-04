#include <iostream>
#include "Primitives.h"
#define TEMPLATE 0

#if TEMPLATE == 1
template<typename T>
std::ostream& operator<<(std::ostream& output, const T& obj) {
	output << obj.getVal();
	return output;
} // end function operator<<

#elif !TEMPLATE
std::ostream& operator<<(std::ostream& output, const IntObject& i_obj) {
	output << i_obj.getVal();
	return output;
} // end function operator<<
#endif