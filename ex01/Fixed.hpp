#ifndef FIXED_HPP
 #define FIXED_HPP

 #include <iostream>
 #include <cmath>

class Fixed
{
	public :
	//---------ex00--------
		Fixed();
		~Fixed();
		Fixed(const Fixed& copyClass);
		Fixed& operator=(const Fixed& rhs);
		int getRawBits(void) const;
		void setRawBits(int const raw);
	//---------ex00--------
	//---------ex01--------
		Fixed(int const i);
		Fixed(float const f);
		float toFloat( void ) const;
		int toInt( void ) const;
	//---------ex01--------
	private :
		int _value;
		static int const _fracBit = 8;
};
std::ostream& operator<<(std::ostream &o, const Fixed& rhs);

#endif