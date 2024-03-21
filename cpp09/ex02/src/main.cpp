/**======================
*            42sp
* @file      : main.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 19/03/2024
*========================**/

#include "../include/PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cout << "Usage: ./pmergme [int] [int]" << std::endl;
		return 1;
	}
	PmergeMe pmm;
	pmm.processInput(argv);
	pmm.validateInput();
	pmm.printContainers();
	return 0;
}
