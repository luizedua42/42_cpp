/**======================
 * ?        ABOUT
 * @file      : main.cpp
 * @author    : luizedua
 * @createdOn : 05/02/2024
 *========================**/

#include "../include/Zombie.hpp"
#include "../include/Colors.hpp"

int main(void) {
	Zombie* fZombie;
	Zombie sZombie;

	std::cout << YELLOW <<"newZombie test------------------------------------------------"
				<< RESET << std::endl;
	fZombie = newZombie("Gordon");
	fZombie->announce();
	delete fZombie;
	std::cout << YELLOW <<"randomChump test----------------------------------------------"
				<< RESET << std::endl;
	randomChump("Eli");
	std::cout << YELLOW <<"Object test---------------------------------------------------"
			<< RESET << std::endl;
	sZombie.setName("Alyx");
	sZombie.announce();
}