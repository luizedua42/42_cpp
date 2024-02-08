/**======================
*            42sp
* @file      : Fixed.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 06/02/2024
*========================**/

#include "../include/Fixed.hpp"

Fixed::Fixed() {
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int nbr) {
	// std::cout << "Int constructor called" << std::endl;
	_rawBits = nbr << _fractBits;
}

Fixed::Fixed(const float nbr) {
	// std::cout << "Float constructor called" << std::endl;
	_rawBits = (roundf(nbr * 256));
}

Fixed::Fixed(const Fixed& rhs){
	// std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
};

Fixed::~Fixed(void){
	// std::cout << "Destructor called" << std::endl;
};

void Fixed::setRawBits(int const raw){
	_rawBits = raw;
};

int Fixed::getRawBits(void) const{
	return _rawBits;
};

float Fixed::toFloat(void)const {
	return ((float)_rawBits / 256);
}

int Fixed::toInt()const {
	return (_rawBits >> _fractBits);
}

const Fixed Fixed::min(const Fixed& n1, const Fixed& n2){
	if(n1._rawBits > n2._rawBits)
		return n2;
	return n1;
}

Fixed Fixed::min(Fixed& n1, Fixed& n2){
	if(n1 > n2)
		return n2;
	return n1;
}
const Fixed Fixed::max(const Fixed& n1, const Fixed& n2){
	if(n1._rawBits < n2._rawBits)
		return n2;
	return n1;
}
Fixed Fixed::max(Fixed& n1, Fixed& n2){
	if(n1 < n2)
		return n2;
	return n1;
};

Fixed& Fixed::operator=(const Fixed& rhs) {
	if(this != &rhs) {
		_rawBits = rhs.getRawBits();
	}
	return *this;
};

std::ostream &operator<<(std::ostream& stream, const Fixed& rhs) {
	stream << rhs.toFloat();
	return stream;
};

bool Fixed::operator<(const Fixed& rhs) {
	return this->toFloat() < rhs.toFloat();
};

bool Fixed::operator>(const Fixed& rhs) {
	return this->toFloat() > rhs.toFloat();
}

bool Fixed::operator>=(const Fixed& rhs) {
	return this->toFloat() >= rhs.toFloat();
};

bool Fixed::operator<=(const Fixed& rhs) {
	return this->toFloat() <= rhs.toFloat();
};

bool Fixed::operator==(const Fixed& rhs) {
	return this->toFloat() == rhs.toFloat();
};

bool Fixed::operator!=(const Fixed& rhs) {
	return this->toFloat() != rhs.toFloat();
};

Fixed Fixed::operator+(const Fixed& rhs) {
	Fixed ret(this->toFloat() + rhs.toFloat());
	return ret;
};

Fixed Fixed::operator-(const Fixed& rhs) {
	Fixed ret(this->toFloat() - rhs.toFloat());
	return ret;
};

Fixed Fixed::operator*(const Fixed& rhs) {
	Fixed ret (this->toFloat() * rhs.toFloat());
	return ret;
};

Fixed Fixed::operator/(const Fixed& rhs) {
	Fixed ret (this->toFloat() / rhs.toFloat());
	return ret;
};

Fixed& Fixed::operator++(void) {
	_rawBits += 1;
	return *this;
};

Fixed& Fixed::operator--(void) {
	_rawBits -= 1;
	return *this;
};

Fixed Fixed::operator++(int) {
	Fixed temp(*this);

	++(*this);
	return temp;
};

Fixed Fixed::operator--(int) {
	Fixed temp(*this);

	--(*this);
	return temp;
};