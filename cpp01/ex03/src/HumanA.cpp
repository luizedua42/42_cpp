/**======================
 * ?        ABOUT
 * @file      : HumanA.cpp
 * @author    : luizedua
 * @createdOn : 05/02/2024
 *========================**/

#include "../include/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) {
	setName(name);
	setWeapon(weapon);
}

HumanA::~HumanA(){}

void HumanA::setName(std::string name){
	_name = name;
}

std::string HumanA::getName(void) {
	return _name;
}

void HumanA::setWeapon(Weapon& weapon){
	_weapon = &weapon;
}

void HumanA::attack(void) {
	std::cout << getName() << " attacks with their " << _weapon->getType() << std::endl;
}