/**======================
*            42sp
* @file      : WrongAnimal.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 29/02/2024
*========================**/

#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << GREEN << "WrongAnimal Default constructor called" << RESET << std::endl;
};

WrongAnimal::WrongAnimal(const WrongAnimal& rhs){
	std::cout << YELLOW << "WrongAnimal copied" << RESET << std::endl;
	*this = rhs;
};

WrongAnimal::~WrongAnimal(void){
	std::cout << RED << "WrongAnimal destroyed" << RESET << std::endl;
};

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs) {
	if(this != &rhs) {
		_type = rhs._type;
	}
	return *this;
};

void WrongAnimal::makeSound() const{
	std::cout << "* " << _type << " makes a steel tube falling sound *" << std::endl;
};

std::string WrongAnimal::getType(void) const {
	return (_type);
};