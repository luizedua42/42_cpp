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
	void (Harl::*members[4])(void) = \
		{&Harl::debug,  &Harl::info, &Harl::warning, &Harl::error};

	std::string names[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	for (int i = 0; i < 4; i++) {
		if (level == names[i])
			(this->*members[i])();
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