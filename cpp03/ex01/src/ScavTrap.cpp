/**======================
*            42sp
* @file      : ScavTrap.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 19/02/2024
*========================**/

#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap("John Doe"){
	std::cout << YELLOW << "ScavTrap "<< _name << " has been constructed" << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << YELLOW << "ScavTrap "<< _name << " has been constructed" << RESET << std::endl;
};

ScavTrap::ScavTrap(const ScavTrap& rhs) : ClapTrap(rhs._name){
	*this = rhs;
};

ScavTrap::~ScavTrap(void){
	std::cout << RED << _name << " has been destroyed" << RESET << std::endl;
};

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs) {
	if(this != &rhs) {
		_name = rhs.getName();
		_hitPoints = rhs.getHit();
		_attackDamage = rhs.getAttack();
		_energyPoints = rhs.getEnergy();
	}
	return *this;
};

void ScavTrap::attack(const std::string& target){
	if(this->_hitPoints < 1){
		std::cout << TRAP << "ScavTrap " << RESET << this->getName() << YELLOW <<" is dead"<< RESET << std::endl;
		return ;
	}
	if(this->_energyPoints == 0){
		std::cout << TRAP << "ScavTrap " << RESET << this->getName() << YELLOW <<" tried attacking, but no energy left"<< RESET << std::endl;
		return ;
	}
	std::cout << TRAP << "ScavTrap " << RESET << this->getName() <<" attacks " << target
	<< " causing " << RED << this->getAttack() << RESET << " points of damage !" << std::endl;
	--this->_energyPoints;
};

void ScavTrap::guardGate(void){
	std::cout << TRAP << "ScavTrap " << RESET << this->getName() 
	<< " is in " << BLUE << "Gate Keeper mode" << RESET << std::endl;
}