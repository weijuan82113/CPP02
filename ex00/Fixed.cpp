#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copyClass)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copyClass;
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
	if (this != &rhs)
	{
		std::cout << "Copy assignment operator called" << std::endl;
		_value = rhs.getRawBits();
	}
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}
