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
	//---------ex02--------

	// prefix increment,decrement ++f,--f
		Fixed& operator ++ (void);
		Fixed& operator -- (void);
	// postfix increment,decrement f++,f--
		Fixed operator ++ (int);
		Fixed operator -- (int);
	//--- +,-,*,/ ---
		Fixed operator + (const Fixed& rhs) const;
		Fixed operator - (const Fixed& rhs) const;
		Fixed operator * (const Fixed& rhs) const;
		Fixed operator / (const Fixed& rhs) const;
	//--- >,<,>=,<=,==,!= ---
		bool operator > (const Fixed& rhs) const;
		bool operator < (const Fixed& rhs) const;
		bool operator >= (const Fixed& rhs) const;
		bool operator <= (const Fixed& rhs) const;
		bool operator == (const Fixed& rhs) const;
		bool operator != (const Fixed& rhs) const;
	//--- min,max ----
		static Fixed& min(Fixed& lhs, Fixed& rhs);
		static Fixed& max(Fixed& lhs, Fixed& rhs);
	//--- const min,max ----
		static const Fixed& min(const Fixed& lhs, const Fixed& rhs);
		static const Fixed& max(const Fixed& lhs, const Fixed& rhs);

	//---------ex02--------
	private :
		int _value;
		static int const _fracBit = 8;

};
//---------ex01--------
std::ostream& operator<<(std::ostream &o, const Fixed& fix);

//---------ex01--------

#endif