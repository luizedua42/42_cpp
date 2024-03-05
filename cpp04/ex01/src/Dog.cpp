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
	std::cout << GREEN << _type << " default constructor" << RESET << std::endl;
	_brain = new Brain();
};

Dog::Dog(const Dog& rhs){
	_brain = new Brain();
	*this = rhs;
	std::cout << YELLOW << _type << " copy constructor" << RESET << std::endl;
};

Dog::~Dog(void){
	delete _brain;
	std::cout << RED << _type << " destructor" << RESET << std::endl;
};

void Dog::makeSound() const{
	std::cout << "woof woof" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs) {
	if(this != &rhs) {
		_type = rhs._type;
		*_brain = *(rhs._brain);
	}
	std::cout << YELLOW << _type << " copy operator" << RESET << std::endl;
	return *this;
};

Brain* Dog::getBrain(void) const {
	return _brain;;
};