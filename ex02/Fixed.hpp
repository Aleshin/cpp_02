#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
private:
	int					_value;
	static const int	_fractionalBits = 8;

public:
	Fixed();                          // Default constructor
	Fixed(const int n);              // New: int constructor
	Fixed(const float f);            // New: float constructor
	Fixed(const Fixed& other);       // Copy constructor
	Fixed& operator=(const Fixed& other); // overload =
	~Fixed();                        // Destructor

// The 6 comparison operators: >, <, >=, <=, ==, and !=.
	bool operator>(const Fixed& rhs) const;
	bool operator<(const Fixed& rhs) const;
	bool operator>=(const Fixed& rhs) const;
	bool operator<=(const Fixed& rhs) const;
	bool operator==(const Fixed& rhs) const;
	bool operator!=(const Fixed& rhs) const;

// The 4 arithmetic operators: +, -, *, and /.
	Fixed operator+(const Fixed& rhs) const;
	Fixed operator-(const Fixed& rhs) const;
	Fixed operator*(const Fixed& rhs) const;
	Fixed operator/(const Fixed& rhs) const;

// pre-increment, post-increment, pre-decrement, post-decrement operators
	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);

// min and max functions
static Fixed& min(Fixed& a, Fixed& b);
static const Fixed& min(const Fixed& a, const Fixed& b);
static Fixed& max(Fixed& a, Fixed& b);
static const Fixed& max(const Fixed& a, const Fixed& b);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	float	toFloat(void) const;     // New
	int		toInt(void) const;       // New
};

std::ostream& operator<<(std::ostream& out, const Fixed& value); // overload <<

#endif
