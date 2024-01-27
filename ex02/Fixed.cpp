#include "Fixed.hpp"

//---------ex00--------

Fixed::Fixed()
{
	_value = 0;
};

Fixed::~Fixed()
{
};

Fixed::Fixed(const Fixed& copyClass)
{
	*this = copyClass;
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
	if (this != &rhs)
	{
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
	_value = raw;
};

//---------ex00--------

//---------ex01--------

Fixed::Fixed(int const i)
{
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

std::ostream& operator<<(std::ostream &o, const Fixed& fix)
{
	o << fix.toFloat();
	return (o);
}

//---------ex01--------

//---------ex02--------

//---  prefix ++f,--f  ---
Fixed& Fixed::operator++()
{
	Fixed& temp = *this;
	temp._value = ++_value;
	return temp;
}

Fixed& Fixed::operator--()
{
	Fixed& temp = *this;
	temp._value = --_value;
	return temp;
}

//---  postfix f++,f--  ---

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	temp._value = _value++;
	return temp;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	temp._value = _value--;
	return temp;
}

//--- +,-,*,/ ---

Fixed Fixed::operator+(const Fixed& rhs) const
{
	return (Fixed((this->toFloat()) + (rhs.toFloat())));
}

Fixed Fixed::operator-(const Fixed& rhs) const
{
	return (Fixed((this->toFloat()) - (rhs.toFloat())));
}

Fixed Fixed::operator*(const Fixed& rhs) const
{
	return (Fixed((this->toFloat()) * (rhs.toFloat())));
}

Fixed Fixed::operator/(const Fixed& rhs) const
{
	return (Fixed((this->toFloat()) / (rhs.toFloat())));
}

//--- >,<,>=,<=,==,!= ---

bool Fixed::operator > (const Fixed& rhs) const
{
	return (this->getRawBits() > rhs.getRawBits());
}

bool Fixed::operator < (const Fixed& rhs) const
{
	return (this->getRawBits() < rhs.getRawBits());
}

bool Fixed::operator >= (const Fixed& rhs) const
{
	return (this->getRawBits() >= rhs.getRawBits());
}

bool Fixed::operator <= (const Fixed& rhs) const
{
	return (this->getRawBits() <= rhs.getRawBits());
}

bool Fixed::operator == (const Fixed& rhs) const
{
	return (this->getRawBits() == rhs.getRawBits());
}

bool Fixed::operator != (const Fixed& rhs) const
{
	return (this->getRawBits() != rhs.getRawBits());
}

//--- min,max ---
Fixed& Fixed::min(Fixed& lhs, Fixed& rhs)
{
	if (lhs >= rhs)
		return (rhs);
	else
		return (lhs);
}

Fixed& Fixed::max(Fixed& lhs, Fixed& rhs)
{
	if (lhs >= rhs)
		return (lhs);
	else
		return (rhs);
}

//--- const min, const max
const Fixed& Fixed::min(const Fixed& lhs, const Fixed& rhs)
{
	if (lhs >= rhs)
		return (rhs);
	else
		return (lhs);
}

const Fixed& Fixed::max(const Fixed& lhs, const Fixed& rhs)
{
	if (lhs >= rhs)
		return (lhs);
	else
		return (rhs);
}
//---------ex02--------