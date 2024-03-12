#include "../include/ScalarConverter.hpp"
#include <limits>
#include <sstream>
#include <string>
#include <cmath>

static std::string abstractionFloat(double num,std::string const& rest) {
	std::ostringstream oss;
	if(isinff(static_cast<float>(num)))
		return (std::string("Impossible"));
	oss << static_cast<float>(num) << rest + "f";
	return oss.str();
}

static std::string abstractionChar(int num) {
	return (num >= 32 && num <= 126 ?
		std::string("''").insert(1,1, static_cast<char>(num)) : 
		num < 0 || num > 127 ?
			std::string("Impossible") : std::string("Non displayable"));
}

static std::string abstractionChar(double num)
{
	return static_cast<int>(num) >= 32 && static_cast<int>(num) <= 126 ?
		std::string("''").insert(1, 1, static_cast<char>(num)) :
		static_cast<int>(num) < 0 || static_cast<int>(num) > 127 ?
			std::string("impossible") : std::string("Non displayable");
}

static std::string abstractionInt(double num) {
	std::ostringstream oss;
	if(num < static_cast<double>(std::numeric_limits<int>::min()) || num > static_cast<double>(std::numeric_limits<int>::max()))
		return ("Impossible");
	oss << static_cast<int>(num);
	return oss.str();
}

static std::string abstractionChar(char byte)
{
	return (byte >= ' ' && byte <= '~' ?
		std::string("''").insert(1, 1, byte) : std::string("Non displayable"));
}

void printImpossible(void) {
	std::cout << "char: impossible" << std::endl
		<< "int: impossible" << std::endl
		<< "float: impossible "  << std::endl
		<< "double: impossible " << std::endl;
}

void printNan(void){
	std::cout << "char: impossible" << std::endl
		<< "int: impossible" << std::endl
		<< "float: nanf" << std::endl
		<< "double: nan" << std::endl;
}

void printInf(Types type){
	std::cout << "char: impossible" << std::endl
		<< "int: impossible" << std::endl
		<< "float: " << (type == NINF ? "-inff" : "+inff") << std::endl
		<< "double: " << (type == NINF ? "-inf" : "+inf") << std::endl;
}

void printFloat(std::string const& str) {
	double numD = static_cast<double>(0);
	numD = atof(str.c_str());

	std::string charValue(abstractionChar(numD));
	std::string hasRest (fmod(numD, 1) == 0.0 ? ".0" : "");
	std::string intValue (abstractionInt(numD));
	std::string floatValue (abstractionFloat(numD, hasRest));
	
	std::cout << "char: " << charValue << std::endl
		<< "int: " << intValue << std::endl
		<< "float: " << floatValue << hasRest << std::endl
		<< "double: " << numD << hasRest << std::endl;
}

void printInt(std::string const& str) {
	int num = 0;
	num = atoi(str.c_str());

	std::string charValue(abstractionChar(num));
	std::cout << "char: " << charValue << std::endl
		<< "int: " << num << std::endl
		<< "float: " << static_cast<float>(num) << ".0f" << std::endl
		<< "double: " << static_cast<double>(num)<< ".0"<< std::endl;
}

void printChar(std::string const& str) {
	char byte = str[0];
	std::string charValue(abstractionChar(byte));
	std::cout << "char: " << charValue << std::endl
		<< "int: " << static_cast<int>(byte) << std::endl
		<< "float: " << static_cast<float>(byte) << ".0f" << std::endl
		<< "double: " << static_cast<double>(byte) << ".0" << std::endl;
}
