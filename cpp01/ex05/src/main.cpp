/**======================
*            42sp
* @file      : main.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 06/02/2024
*========================**/

#include "../include/Harl.hpp"

int main() {
	Harl hevSuit;

	srand(time(NULL));
	hevSuit.complain("DEBUG");
	hevSuit.complain("INFO");
	hevSuit.complain("WARNING");
	hevSuit.complain("ERROR");
	return 0;
}