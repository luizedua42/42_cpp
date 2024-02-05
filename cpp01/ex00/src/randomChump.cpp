/**======================
 * ?        ABOUT
 * @file      : randomChump.cpp
 * @author    : luizedua
 * @createdOn : 05/02/2024
 *========================**/

#include "../include/Zombie.hpp"

void randomChump(std::string name) {
	Zombie randomChump;

	randomChump.setName(name);
	randomChump.announce();
}