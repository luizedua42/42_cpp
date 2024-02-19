/**======================
*            42sp
* @file      : main.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 19/02/2024
*========================**/

#include "../include/ClapTrap.hpp"

int main (void){
	ClapTrap Gordon("Gordon");
	ClapTrap Headcrab("Headcrab");

	Headcrab.attack(Gordon.getName());
	Gordon.takeDamage(Headcrab.getAttack());
	Headcrab.attack(Gordon.getName());
	Gordon.takeDamage(Headcrab.getAttack());
	Headcrab.attack(Gordon.getName());
	Gordon.takeDamage(Headcrab.getAttack());
	Headcrab.attack(Gordon.getName());
	Gordon.takeDamage(Headcrab.getAttack());
	Headcrab.attack(Gordon.getName());
	Gordon.takeDamage(Headcrab.getAttack());


	Gordon.attack(Headcrab.getName());
	Headcrab.takeDamage(Gordon.getAttack());
	Gordon.attack(Headcrab.getName());
	Headcrab.takeDamage(Gordon.getAttack());
	Gordon.attack(Headcrab.getName());
	Headcrab.takeDamage(Gordon.getAttack());
	Gordon.attack(Headcrab.getName());
	Headcrab.takeDamage(Gordon.getAttack());
	Gordon.attack(Headcrab.getName());
	Headcrab.takeDamage(Gordon.getAttack());

	
	Gordon.beRepaired(10);
	Gordon.beRepaired(10);
	Gordon.beRepaired(10);
	Gordon.beRepaired(10);
	Gordon.beRepaired(10);
	
	Headcrab.beRepaired(10);
	Headcrab.beRepaired(10);
	Headcrab.beRepaired(10);
	Headcrab.beRepaired(10);
	Headcrab.beRepaired(10);
	Headcrab.attack(Gordon.getName());
	Gordon.attack(Headcrab.getName());

	return 0;
}