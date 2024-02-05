/**======================
 * ?        ABOUT
 * @file      : newHorde.cpp
 * @author    : luizedua
 * @createdOn : 05/02/2024
 *========================**/

#include "../include/Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	Zombie* horde = new Zombie[N];

	for(int i = 0; i < N; i++){
		horde->setName(name);
	}
	return horde;
}