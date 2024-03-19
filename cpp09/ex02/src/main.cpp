/**======================
*            42sp
* @file      : main.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 19/03/2024
*========================**/

#include "../include/PmergeMe.hpp"

int main(void) {
	PmergeMe p;
	PmergeMe p2(p);
	PmergeMe p3 = p2;

	return 0;
}
