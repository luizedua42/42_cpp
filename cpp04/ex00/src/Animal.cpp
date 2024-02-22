/**======================
*            42sp
* @file      : Animal.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 22/02/2024
*========================**/

#include "../include/Animal.hpp"

Animal::Animal() {
	std::cout << GREEN << "Animal constructor called" << RESET << std::endl;
};
Animal::Animal(const Animal& rhs){
	std::cout << YELLOW << "Animal copied" << RESET << std::endl;
	*this = rhs;
};
Animal::~Animal(void){
	std::cout << RED << "Animal destroyed" << RESET << std::endl;
};
Animal& Animal::operator=(const Animal& rhs) {
	if(this != &rhs) {
		_type = rhs._type;
	}
	return *this;
};

void Animal::makeSound(void) const{
	std::cout << "Bonk!" << std::endl;
}

std::string Animal::getType() const{
	return _type;
}

void Animal::setType(std::string type){
	_type = type;
}