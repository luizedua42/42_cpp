/**======================
 * ?        ABOUT
 * @file      : main.cpp
 * @author    : luizedua
 * @createdOn : 05/02/2024
 *========================**/

#include <iostream>

int main(void) {
	std::string brain = "HI THIS IS BRAIN";
	std::string* brainPTR = &brain;
	std::string& brainREF = brain;

	std::cout << "ADRESSES====================================================="
				<< std::endl;
	std::cout << "var: " << &brain << std::endl;
	std::cout << "ptr: " << brainPTR << std::endl;
	std::cout << "ref: " << &brainREF << std::endl;
	std::cout << "VALUES======================================================="
				<< std::endl;
	std::cout << "var: " << brain << std::endl;
	std::cout << "ptr: " << *brainPTR << std::endl;
	std::cout << "ref: " << brainREF << std::endl;
}