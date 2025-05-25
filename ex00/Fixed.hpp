#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
private:
	int					_raw;
	static const int	_fractional_bits = 8;

public:
	Fixed();                            // Default constructor
	Fixed(const Fixed &other);          // Copy constructor
	Fixed &operator=(const Fixed &rhs); // Copy assignment operator
	~Fixed();                           // Destructor

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif
