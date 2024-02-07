/**======================
*            42sp
* @file      : Fixed.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 06/02/2024
*========================**/

#include "../include/Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int nbr) {
	std::cout << "Int constructor called" << std::endl;
	_rawBits = nbr << _fractBits;
}

Fixed::Fixed(const float nbr) {
	std::cout << "Float constructor called" << std::endl;
	_rawBits = (roundf(nbr * 256));
}

Fixed::Fixed(const Fixed& rhs){
	std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
};

Fixed::~Fixed(void){
	std::cout << "Destructor called" << std::endl;
};

void Fixed::setRawBits(int const raw){
	_rawBits = raw;
};

int Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return _rawBits;
};

float Fixed:: toFloat(void)const {
	return ((float)_rawBits / 256);
}

int Fixed:: toInt()const {
	return (_rawBits >> _fractBits);
}
Fixed& Fixed::operator=(const Fixed& rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &rhs) {
		_rawBits = rhs.getRawBits();
	}
	return *this;
};

std::ostream &operator<<(std::ostream& lhs, const Fixed& rhs) {
	lhs << rhs.toFloat();
	return lhs;
};