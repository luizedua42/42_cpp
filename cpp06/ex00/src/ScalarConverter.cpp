/**======================
*            42sp
* @file      : ScalarConverter.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 07/03/2024
*========================**/

#include "../include/ScalarConverter.hpp"

void printNan(void);
void printInf(Types type);
void printImpossible(void);
void printInt(std::string const& str);
void printChar(std::string const& str);
void printFloat(std::string const& str);
Types detectType(std::string const& str);


ScalarConverter::ScalarConverter() {
	std::cout << MAGENTA << "Default constructor called" RESET << std::endl;
}
ScalarConverter::ScalarConverter(const ScalarConverter& rhs){
	std::cout << MAGENTA << "Copy constructor called" RESET << std::endl;
	*this = rhs;
};
ScalarConverter::~ScalarConverter(void){
	std::cout << RED << "Destructor called" RESET << std::endl;
};
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) {
	std::cout << MAGENTA << "Copy assignment operator called" RESET << std::endl;
	(void)rhs;
	return *this;
};

void ScalarConverter::converter(std::string const& str) {
	size_t start = str.find_first_not_of(" \t");
	size_t end = str.find_last_not_of(" \t");

	if (start != std::string::npos && end != std::string::npos) {
		const_cast<std::string&>(str) = str.substr(start, end - start + 1);
	} else if (start != std::string::npos) {
		const_cast<std::string&>(str) = str.substr(start);
	} else if (end != std::string::npos) {
		const_cast<std::string&>(str) = str.substr(0, end + 1);
	}

	Types type = detectType(str);
	switch (type) {
		case INVALID:
			printImpossible();
			break;
		case TNAN:
			printNan();
			break;
		case NINF:
		case PINF:
			printInf(type);
			break;
		case CHAR:
			printChar(str);
			break;
		case INT:
			printInt(str);
			break;
		case FLOAT:
		case DOUBLE:
			printFloat(str);
			break;
	}
}