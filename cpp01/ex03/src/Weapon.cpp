/**======================
 * ?        ABOUT
 * @file      : Weapon.cpp
 * @author    : luizedua
 * @createdOn : 05/02/2024
 *========================**/

#include "../include/Weapon.hpp"

Weapon::Weapon(std::string type) {
	setType(type);
}

Weapon::~Weapon() {}

void Weapon::setType(std::string type) {
	_type = type;
}

const std::string& Weapon::getType(void) {
	return _type;
}

