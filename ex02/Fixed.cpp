#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _value(0) {
}

Fixed::Fixed(const int n) {
	_value = n << _fractionalBits;
}

Fixed::Fixed(const float f) {
	_value = roundf(f * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other) {
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other)
		_value = other._value;
	return *this;
}

Fixed::~Fixed() {
}

// The 6 comparison operators: >, <, >=, <=, ==, and !=.
bool Fixed::operator>(const Fixed& rhs) const {
	return this->_value > rhs._value;
}
bool Fixed::operator<(const Fixed& rhs) const {
	return this->_value < rhs._value;
}
bool Fixed::operator>=(const Fixed& rhs) const {
	return this->_value >= rhs._value;
}
bool Fixed::operator<=(const Fixed& rhs) const {
	return this->_value <= rhs._value;
}
bool Fixed::operator==(const Fixed& rhs) const {
	return this->_value == rhs._value;
}
bool Fixed::operator!=(const Fixed& rhs) const {
	return this->_value != rhs._value;
}

// The 4 arithmetic operators: +, -, *, and /.
Fixed Fixed::operator+(const Fixed& rhs) const {
	Fixed result;
	result.setRawBits(this->_value + rhs._value);
	return result;
}
Fixed Fixed::operator-(const Fixed& rhs) const {
	Fixed result;
	result.setRawBits(this->_value - rhs._value);
	return result;
}
Fixed Fixed::operator*(const Fixed& rhs) const {
	Fixed result;
	long tmp = static_cast<long>(this->_value) * rhs._value;
	result.setRawBits(static_cast<int>(tmp >> _fractionalBits));
	return result;
}
Fixed Fixed::operator/(const Fixed& rhs) const {
	Fixed result;
	long tmp = (static_cast<long>(this->_value) << _fractionalBits) / rhs._value;
	result.setRawBits(static_cast<int>(tmp));
	return result;
}

// pre-increment, post-increment, pre-decrement, post-decrement operators
Fixed& Fixed::operator++() {
	++_value;
	return *this;
}
Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	++_value;
	return temp;
}
Fixed& Fixed::operator--() {
	--_value;
	return *this;
}
Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	--_value;
	return temp;
}

// min and max functions with ternary operator
// condition ? value_if_true : value_if_false;
Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
}
Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
}

int Fixed::getRawBits(void) const {
	return _value;
}

void Fixed::setRawBits(int const raw) {
	_value = raw;
}

float Fixed::toFloat(void) const {
	return (float)_value / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
	return _value >> _fractionalBits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& value) {
	out << value.toFloat();
	return out;
}
