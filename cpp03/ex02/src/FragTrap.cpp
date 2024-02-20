/**======================
*            42sp
* @file      : FragTrap.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 20/02/2024
*========================**/

#include "../include/FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap("John Doe"){
	std::cout << YELLOW << "FragTrap "<< _name << " has been constructed" << RESET << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << YELLOW << "FragTrap "<< _name << " has been constructed" << RESET << std::endl;
};

FragTrap::FragTrap(const FragTrap& rhs) : ClapTrap(rhs._name){
	*this = rhs;
};

FragTrap::~FragTrap(void){
	std::cout <<MAGENTA "FragTrap " << RED << _name << " has been destroyed" << RESET << std::endl;
};

FragTrap& FragTrap::operator=(const FragTrap& rhs) {
	if(this != &rhs) {
		_name = rhs.getName();
		_hitPoints = rhs.getHit();
		_attackDamage = rhs.getAttack();
		_energyPoints = rhs.getEnergy();
	}
	return *this;
};

void FragTrap::highFivesGuys(void){
	std::cout <<MAGENTA "FragTrap " << RESET << _name << " wants a HIGHFIVE" << std::endl;
}