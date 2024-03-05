/**======================
*            42sp
* @file      : AAnimal.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 22/02/2024
*========================**/

#include "../include/AAnimal.hpp"

AAnimal::AAnimal() {
	std::cout << MAGENTA << "AAnimal default constructor" << RESET << std::endl;
};
AAnimal::AAnimal(const AAnimal& rhs){
	std::cout << YELLOW << "AAnimal copy constructor		" << RESET << std::endl;
	*this = rhs;
};
AAnimal::~AAnimal(void){
	std::cout << RED << "AAnimal destroyed" << RESET << std::endl;
};
AAnimal& AAnimal::operator=(const AAnimal& rhs) {
	if(this != &rhs) {
		_type = rhs._type;
	}
	return *this;
};

void AAnimal::makeSound(void) const{
	std::cout << "Bonk!" << std::endl;
}

std::string AAnimal::getType() const{
	return _type;
}

void AAnimal::setType(std::string type){
	_type = type;
};
