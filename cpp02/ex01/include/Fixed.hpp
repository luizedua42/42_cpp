/**======================
*            42sp
* @file      : Fixed.hpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 06/02/2024
*========================**/

#include <iostream>
#include <cmath>

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

		int		getRawBits(void) const;
		int		toInt(void);
		void	setRawBits(int const raw);
		float	toFloat(void);
};
#endif