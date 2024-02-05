/**======================
 * ?        ABOUT
 * @file      : newZombie.hpp
 * @author    : luizedua
 * @createdOn : 05/02/2024
 *========================**/

#include "../include/Zombie.hpp"

Zombie* newZombie(std::string name) {
	Zombie* zombie = new Zombie;

	zombie->setName(name);
	return zombie;
}