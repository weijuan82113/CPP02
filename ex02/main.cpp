// 0
// 0.00390625
// 0.00390625
// 0.00390625
// 0.0078125
// 10.1016
// 10.1016

#include "Fixed.hpp"

#define debug(a) std::cout << #a << " : " << a << std::endl

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	// Fixed a(100000);
	// Fixed b(100001);
	// ++a;
	// debug((a==b));
	// debug((a>=b));
	// debug((a<=b));
	// debug((a>b));
	// debug((a<b));
	// debug((a!=b));
	// debug(Fixed::max(a,b));
	// debug(Fixed::min(a,b));
	return 0;
}