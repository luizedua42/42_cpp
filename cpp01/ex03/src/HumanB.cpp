/**======================
 * ?        ABOUT
 * @file      : HumanB.cpp
 * @author    : luizedua
 * @createdOn : 05/02/2024
 *========================**/

#include "../include/HumanB.hpp"


HumanB::HumanB(std::string name) {
	setName(name);
	_weapon = NULL;
}

HumanB::~HumanB(){}

void HumanB::setName(std::string name){
	_name = name;
}

std::string HumanB::getName(void) {
	return _name;
}

void HumanB::setWeapon(Weapon& weapon){
	_weapon = &weapon;
}

void HumanB::attack(void) {
	std::cout << getName() << " attacks with their " << _weapon->getType() << std::endl;
}