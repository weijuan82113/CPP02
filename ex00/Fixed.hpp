#ifndef FIXED_HPP
 #define FIXED_HPP
#include <iostream>

class Fixed
{
	public :
		Fixed();
		~Fixed();
		Fixed(const Fixed& copyClass);
		Fixed& operator=(const Fixed& other);
		int getRawBits(void) const;
		void setRawBits(int const raw);
	private :
		int	_value;
		static int const _fracBit = 8;
};

#endif