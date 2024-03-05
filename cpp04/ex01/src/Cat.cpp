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
	std::cout << GREEN << _type << " default constructor" << RESET << std::endl;
	_brain = new Brain();
};

Cat::Cat(const Cat& rhs){
	_brain = new Brain();
	*this = rhs;
	std::cout << YELLOW << _type << " copy constructor" << RESET << std::endl;
};

Cat::~Cat(void){
	delete _brain;
	std::cout << RED << _type << " destructor" << RESET << std::endl;
};

void Cat::makeSound() const{
	std::cout << "meow meow" << std::endl;
};

Cat& Cat::operator=(const Cat& rhs) {
	if(this != &rhs) {
		_type = rhs._type;
		*_brain = *(rhs._brain);
	}
	std::cout << YELLOW << _type << " copy operator" << RESET << std::endl;
	return *this;
};

Brain* Cat::getBrain(void) const {
	return _brain;;
};