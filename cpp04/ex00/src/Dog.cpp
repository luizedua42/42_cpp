/**======================
*            42sp
* @file      : Dog.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 22/02/2024
*========================**/

#include "../include/Dog.hpp"

Dog::Dog() : Animal() {
	setType("Dog");
	std::cout << GREEN << _type << " constructor called" << RESET << std::endl;
};

Dog::Dog(const Dog& rhs){
	std::cout << YELLOW << _type << " copied" << RESET << std::endl;
	*this = rhs;
};

Dog::~Dog(void){
	std::cout << RED << _type << " destroyed" << RESET << std::endl;
};

void Dog::makeSound() const{
	std::cout << "woof woof" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs) {
	if(this != &rhs) {
		_type = rhs._type;
	}
	return *this;
};
