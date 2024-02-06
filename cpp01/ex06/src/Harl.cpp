/**======================
*            42sp
* @file      : Harl.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 06/02/2024
*========================**/

#include "../include/Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void Harl::complain(std::string level) {
	std::string names[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;
	for (; i < 4; i++) {
		if (level == names[i])
			break;
	}
	switch (i) {
		case 0:
			Harl::debug();
		case 1:
			Harl::info();
		case 2:
			Harl::warning();
		case 3:
			Harl::error();
			break;
		default:
			std::cout << "Automatic target acquisition system deactivated." << std::endl;
	}
}

void Harl::debug(void) {
	std::cout << "Welcome to the HEV Mark 4 Protective System, "
				<< "for use in hazardous environment conditions." << std::endl;
}
void Harl::info(void) {
	int nbr = 1+ (rand() % 100);
	std::cout << "Power " << nbr << " percent" << std::endl;
}
void Harl::warning(void) {
	std::cout << "Warning: Vital signs critical. Evacuate area." << std::endl;
}
void Harl::error(void) {
	std::cout << "Insufficient power. HEV shutting down." << std::endl;
}