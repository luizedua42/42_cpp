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
		Fixed(const int);
		Fixed(const float);
		Fixed(const Fixed& rhs);
		~Fixed(void);
		Fixed& operator=(const Fixed& rhs);

		int		getRawBits(void) const;
		int		toInt(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		static const Fixed min(const Fixed& n1, const Fixed& n2);
		static Fixed min(Fixed& n1, Fixed& n2);
		static const Fixed max(const Fixed& n1, const Fixed& n2);
		static Fixed max(Fixed& n1, Fixed& n2);
		bool	operator<(const Fixed& rhs);
		bool	operator>(const Fixed& rhs);
		bool	operator>=(const Fixed& rhs);
		bool	operator<=(const Fixed& rhs);
		bool	operator==(const Fixed& rhs);
		bool	operator!=(const Fixed& rhs);
		Fixed	operator+(const Fixed& rhs);
		Fixed	operator-(const Fixed& rhs);
		Fixed	operator*(const Fixed& rhs);
		Fixed	operator/(const Fixed& rhs);
		Fixed&	operator++(void);
		Fixed&	operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);
};

std::ostream& operator<<(std::ostream &lhs, const Fixed& rhs);

#endif