/**======================
 * ?        ABOUT
 * @file      : main.cpp
 * @author    : luizedua
 * @createdOn : 05/02/2024
 *========================**/

#include "../include/HumanA.hpp"
#include "../include/HumanB.hpp"
#include "../include/Weapon.hpp"

int main(void) {
{
	Weapon club = Weapon("crude spiked club");
	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();
}
{
	Weapon club = Weapon("crude spiked club");
	HumanB jim("Jim");
	jim.setWeapon(club);
	jim.attack();
	club.setType("some other type of club");
	jim.attack();
}
return 0;
}
