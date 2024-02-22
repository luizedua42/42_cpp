/**======================
*            42sp
* @file      : Cat.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 22/02/2024
*========================**/

#include "../include/Cat.hpp"

Cat::Cat() : Animal() {
	setType("Cat");
	std::cout << GREEN  << _type << " constructor called" << RESET << std::endl;
};

Cat::Cat(const Cat& rhs){
	std::cout << YELLOW << _type << " copied" << RESET << std::endl;
	*this = rhs;
};

Cat::~Cat(void){
	std::cout << RED << _type << " destroyed" << RESET << std::endl;
};

void Cat::makeSound() const{
	std::cout << "meow meow" << std::endl;
};

Cat& Cat::operator=(const Cat& rhs) {
	if(this != &rhs) {
		_type = rhs._type;
	}
	return *this;
};
