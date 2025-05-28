#include <iostream>
#include "Fixed.hpp"

int main(void) {
Fixed a;
Fixed const b(Fixed(5.05f) * Fixed(2));

std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;

std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
return 0;
}
/*
    Fixed a(20);
	Fixed b(10);

	if (a > b)
		std::cout << a << " > " << b << std::endl;
	if (a < b)
		std::cout << a << " < " << b << std::endl;
	if (a >= b)
		std::cout << a << " >= " << b << std::endl;
	if (a <= b)
		std::cout << a << " <= " << b << std::endl;
	if (a == b)
		std::cout << a << " == " << b << std::endl;
	if (a != b)
		std::cout << a << " != " << b << std::endl;

    std::cout << a <<" + " << b << " = " << a + b << std::endl;
    std::cout << a <<" - " << b << " = " << a - b << std::endl;
    std::cout << a <<" * " << b << " = " << a * b << std::endl;
    std::cout << a <<" / " << b << " = " << a / b << std::endl;

    std::cout << "a = " << a << ", ++a, a = " << ++a << std::endl;
    std::cout << "a = " << a << ", a++, a = " << a++ << std::endl;
    std::cout << "a = " << a << std::endl;

    Fixed& minimum = Fixed::min(a, b);
    std::cout << "min is " << minimum << std::endl;
    Fixed& maximum = Fixed::max(a, b);
    std::cout << "max is " << maximum << std::endl;

    return 0;
}
*/
