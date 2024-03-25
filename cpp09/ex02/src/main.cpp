/**======================
*            42sp
* @file      : main.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 19/03/2024
*========================**/

#include "../include/PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc < 3) {
		std::cout << "Usage: ./pmergme [int] [int]" << std::endl;
		return 1;
	}
	PmergeMe pmm;
	try{
		clock_t start = clock();
		pmm.processInput(argv);
		clock_t end = clock();
		clock_t dataManageTime = end - start;
		pmm.printContainers(dataManageTime);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
