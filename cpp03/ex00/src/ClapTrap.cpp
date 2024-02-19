/**======================
*            42sp
* @file      : ClapTrap.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 19/02/2024
*========================**/

#include "../include/ClapTrap.hpp"


ClapTrap::ClapTrap(std::string name){
	this->_name = name;
	this->_attackDamage = 0;
	this->_energyPoints = 10;
	this->_hitPoints = 10;
	std::cout << YELLOW << _name << " has been constructed" << RESET << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap& rhs){
	*this = rhs;
};

ClapTrap::~ClapTrap(void){
	std::cout << RED << _name << " has been destroyed" << RESET << std::endl;
};

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs) {
	if(this != &rhs) {
		_name = rhs.getName();
		_hitPoints = rhs.getHit();
		_attackDamage = rhs.getAttack();
		_energyPoints = rhs.getEnergy();
	}
	return *this;
};

void ClapTrap::attack(const std::string& target){
	if(this->_hitPoints < 1){
		std::cout << TRAP << "ClapTrap " << RESET << this->getName() << YELLOW <<" is dead"<< RESET << std::endl;
		return ;
	}
	if(this->_energyPoints == 0){
		std::cout << TRAP << "ClapTrap " << RESET << this->getName() << YELLOW <<" tried attacking, but no energy left"<< RESET << std::endl;
		return ;
	}
	std::cout << TRAP << "ClapTrap " << RESET << this->getName() <<" attacks " << target
	<< " causing " << RED << this->getAttack() << RESET << " points of damage !" << std::endl;
	--this->_energyPoints;
};

void ClapTrap::takeDamage(unsigned int amount){
	if(this->_hitPoints < 1){
		std::cout << TRAP << "ClapTrap " << RESET << this->getName() << YELLOW <<" is dead"<< RESET << std::endl;
		return ;
	}
	std::cout << TRAP << "ClapTrap " << RESET << this->getName() 
	<< " has taken "<< RED  << amount << RESET << " points of damage !" << std::endl;
	this->_hitPoints -= amount;
};

void ClapTrap::beRepaired(unsigned int amount){
	if(this->_hitPoints < 1){
		std::cout << TRAP << "ClapTrap " << RESET << this->getName() << YELLOW <<" is dead"<< RESET << std::endl;
		return ;
	}
	if(this->_energyPoints == 0){
		std::cout << TRAP << "ClapTrap " << RESET << this->getName() << YELLOW <<" tried reapairing, but no energy left"<< RESET << std::endl;
		return ;
	}
	std::cout << TRAP << "ClapTrap " << RESET << this->getName() 
	<< " repaired " << GREEN << amount << RESET << " points of health !" << std::endl;
	_hitPoints += amount; 
	--this->_energyPoints;
};

std::string ClapTrap::getName(void) const{
	return _name;
};

void ClapTrap::setName(std::string name){
	_name = name;
};

int ClapTrap::getHit(void) const{
	return _hitPoints;
};

void ClapTrap::setHit(int hit){
	_hitPoints = hit;
};

int ClapTrap::getEnergy(void) const{
	return _energyPoints;
};

void ClapTrap::setEnergy(int energy){
	_energyPoints = energy;
};

int ClapTrap::getAttack(void) const{
	return _attackDamage;
};

void ClapTrap::setAttack(int attack){
	_attackDamage = attack;
};