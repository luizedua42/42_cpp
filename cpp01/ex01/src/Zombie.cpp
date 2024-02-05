/**======================
 * ?        ABOUT
 * @file      : Zombie.cpp
 * @author    : luizedua
 * @createdOn : 05/02/2024
 *========================**/

#include "../include/Zombie.hpp"
#include "../include/Colors.hpp"


Zombie::Zombie(void) {
	std::cout << GREEN << "Zombie created." << RESET << std::endl;
}

Zombie::~Zombie(void) {
	std::cout << RED << this->getName() << " destroyed." << RESET << std::endl;
}

std::string Zombie::getName(void) {
	return (this->_name);
}

void Zombie::setName(std::string name) {
	
	this->_name = name;
}

void Zombie::announce(void) {
	std::cout << this->getName() << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}