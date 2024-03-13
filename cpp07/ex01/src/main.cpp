/**======================
*            42sp
* @file      : main.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 13/03/2024
*========================**/

#include "../include/iter.hpp"

void intPrinter(int const &i) {
	std::cout << i << " ";
}

void floatPrinter(float const &i) {
	std::cout << i << " ";
}

void stringPrinter(std::string const &i) {
	std::cout << i << " ";
}

int main(void){
	int intArray[] = {1, 2, 3, 4, 5};
	float floatArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::string stringArray[] = {"one", "two", "three", "four", "five"};

	std::cout << "intArray: ";
	iter<int>(intArray, 5, intPrinter);
	std::cout << std::endl;

	std::cout << "floatArray: ";
	iter<float>(floatArray, 5, floatPrinter);
	std::cout << std::endl;

	std::cout << "stringArray: ";
	iter<std::string>(stringArray, 5, stringPrinter);
	std::cout << std::endl;

	return 0;
}