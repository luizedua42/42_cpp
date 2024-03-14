/**======================
*            42sp
* @file      : main.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 14/03/2024
*========================**/

#include "../include/easyfind.hpp"
#include "../include/Colors.hpp"
#include <vector>
#include <deque>
#include <list>
#include <deque>

int main() {
	std::cout << YELLOW << "Testing with vector ========================================" << RESET << std::endl;
	std::vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	try {
		std::cout << GREEN << easyfind(v, 5) << RESET << std::endl;
		std::cout << GREEN << easyfind(v, 11) << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << RED << "Value not found" << RESET << std::endl;
	}
	std::cout << YELLOW << "Testing with list ========================================" << RESET << std::endl;
	std::list<int> l;
	for (int i = 0; i < 10; i++) {
		l.push_back(i);
	}
	try {
		std::cout << GREEN << easyfind(l, 5) << RESET << std::endl;
		std::cout << GREEN << easyfind(l, 11) << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << RED << "Value not found" << RESET << std::endl;
	}
	std::cout << YELLOW << "Testing with deque ========================================" << RESET << std::endl;
	std::deque<int> d;
	for (int i = 0; i < 10; i++) {
		d.push_back(i);
	}
	try {
		std::cout << GREEN << easyfind(d, 5) << RESET << std::endl;
		std::cout << GREEN << easyfind(d, 11) << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << RED << "Value not found" << RESET << std::endl;
	}
	return 0;
}
