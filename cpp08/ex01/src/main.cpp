/**======================
*            42sp
* @file      : main.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 14/03/2024
*========================**/

#include "../include/Span.hpp"
#include "../include/Colors.hpp"
#include <iostream>
#include <cstdlib>

int main(void){
	srand(time(NULL));
	std::cout << YELLOW << "Testing Span ===============================================" << RESET << std::endl;
	Span sp = Span(10);
	int shortS = 0;
	int longS = 0;
	for (int i = 0; i < 10; i++) {
		try{
			sp.addNumber(rand() % 1000);
		} catch (std::exception &e){
			std::cout << RED << "Error: " << e.what() << RESET << std::endl;
		}
	}
	std::cout << YELLOW << "============================================== Numbers added" << RESET << std::endl;
	for	(unsigned long i = 0; i < sp.getNumber().size(); i++) {
		std::cout << GREEN << sp.getNumber()[i] << RESET << std::endl;
	}
	std::cout << YELLOW << "===================================== Testing short and long" << RESET << std::endl;
	try {
		shortS = sp.shortestSpan();
	}
	catch (std::exception &e) {
		std::cout << RED << "Error: " << e.what() << RESET << std::endl;
	}
	try {
		longS = sp.longestSpan();
	}
	catch (std::exception &e) {
		std::cout << RED << "Error: " << e.what() << RESET << std::endl;
	}
	std::cout << GREEN << "Shortest span: " << shortS << RESET << std::endl;
	std::cout << GREEN << "Longest span: " << longS << RESET << std::endl;
	return 0;
}
