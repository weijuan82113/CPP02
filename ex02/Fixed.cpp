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
	_value = static_cast<int>(roundf(f * (1 << this->_fracBit))); //left shift the float by fracBit and roud to integer
}

float Fixed::toFloat( void ) const
{
	float f;
	f = static_cast<float>(getRawBits()) / (1 << this->_fracBit); // right shift the fixed pointed value(cast integer to float first) by fracBit
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
	// have to calculate in int operate because fixed point is used to ultilize the speed of calculation
	int temp = this->getRawBits() + rhs.getRawBits();
	Fixed ret;
	ret.setRawBits(temp);
	return (ret);
}

Fixed Fixed::operator-(const Fixed& rhs) const
{
	int temp = this->getRawBits() - rhs.getRawBits();
	Fixed ret;
	ret.setRawBits(temp);
	return (ret);
}

Fixed Fixed::operator*(const Fixed& rhs) const
{
	//to transfer multipled raw_value to the nomral one
	//ex: frac bit is 1
	//1.1(raw_value: 11) * 1.1(raw_value: 11)
	//= 1.21(raw_value * raw_value is 121 but the normal one is 12.1 so have to transfer to 12.1 (121/10))
	int temp = this->getRawBits() * rhs.getRawBits();
	temp /= (1 << this->_fracBit);
	Fixed ret;
	ret.setRawBits(temp);
	return (ret);
}

Fixed Fixed::operator/(const Fixed& rhs) const
{
	int temp = this->getRawBits() / rhs.getRawBits();
	temp *= (1 << this->_fracBit);
	Fixed ret;
	ret.setRawBits(temp);
	return (ret);
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