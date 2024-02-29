/**======================
*            42sp
* @file      : WrongCat.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 29/02/2024
*========================**/

#include "../include/WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << GREEN << "WrongCat Default constructor called" << RESET << std::endl;
}
WrongCat::WrongCat(const WrongCat& rhs){
	std::cout << YELLOW << "WrongCat copied" << RESET << std::endl;
	*this = rhs;
};
WrongCat::~WrongCat(void){
	std::cout << RED << "WrongCat destroyed" << RESET << std::endl;
};
WrongCat& WrongCat::operator=(const WrongCat& rhs) {
	if(this != &rhs) {
		_type = rhs._type;
	}
	return *this;
};
void WrongCat::makeSound(void) const{
	std::cout << RED << "Damn Son" << RESET << std::endl;
}