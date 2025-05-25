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
	Fixed& operator=(const Fixed& other); // Copy assignment
	~Fixed();                        // Destructor

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	float	toFloat(void) const;     // New
	int		toInt(void) const;       // New
};

std::ostream& operator<<(std::ostream& out, const Fixed& value); // New

#endif
