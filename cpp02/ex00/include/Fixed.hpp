/**======================
*            42sp
* @file      : Fixed.hpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 06/02/2024
*========================**/

#include <iostream>

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
	private:
		int _rawBits;
		static const int _fractBits = 8;

	public:
		Fixed(void);
		Fixed(const Fixed& rhs);
		~Fixed(void);
		Fixed& operator=(const Fixed& rhs);

		void setRawBits(int const raw);
		int getRawBits(void) const;
};
#endif