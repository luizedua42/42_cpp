/**======================
 * ?        ABOUT
 * @file      : main.cpp
 * @author    : luizedua
 * @createdOn : 05/02/2024
 *========================**/

#include "../include/Zombie.hpp"
#include "../include/Colors.hpp"

int main(void) {
	int N = 5;
	std::string name = "Barney";

	std::cout << YELLOW << "zombieHorde test---------------------------------------------"
						<< std::endl;
	Zombie* horde = zombieHorde(N, name);
	for(int i = 0; i < N; i++){
		horde->announce();
	}
	delete[] horde;
}