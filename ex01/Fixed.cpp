#include "Fixed.hpp"

//---------ex00--------

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
};

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
};

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
};

int Fixed::getRawBits(void) const
{
	return (_value);
};

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
};

//---------ex00--------

//---------ex01--------

Fixed::Fixed(int const i)
{
	std::cout << "Int constructor called" << std::endl;
	int positive_flag = true;
	if (i < 0)
		positive_flag = false;
	int temp = i * (1 << this->_fracBit);
	if (positive_flag && temp < 0) //the 31bit of positive num is 0; the the 31bit of negtive num is 1
		temp -= (1 << this->_fracBit);
	else if (!positive_flag && temp > 0)
		temp += (1 << this->_fracBit);
	_value = temp;
}

Fixed::Fixed(float const f)
{
	std::cout << "Float constructor called" << std::endl;
	_value = (int)roundf(f * (1 << this->_fracBit)); //left shift the float by fracBit and roud to integer
}

float Fixed::toFloat( void ) const
{
	float f;

	f = (float)getRawBits() / (1 << this->_fracBit); // right shift the fixed pointed value(cast integer to float first) by fracBit
	return (f);
}

int Fixed::toInt( void ) const
{
	return (getRawBits() / (1 << this->_fracBit));
}

std::ostream& operator<<(std::ostream &o, const Fixed& rhs)
{
	o << rhs.toFloat();
	return (o);
}


//---------ex01--------