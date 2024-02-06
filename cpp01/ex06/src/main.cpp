/**======================
*            42sp
* @file      : main.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 06/02/2024
*========================**/

#include "../include/Harl.hpp"

int main(int argc, char **argv) {
	if(argc != 2) {
		std::cout << "Oh Fiddlesticks!!" << std::endl;
		return 1;
	}
	
	Harl hevSuit;

	srand(time(NULL));
	hevSuit.complain(argv[1]);
	return 0;
}