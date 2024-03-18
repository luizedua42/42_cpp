/**======================
*            42sp
* @file      : main.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 17/03/2024
*========================**/

#include "../include/RPN.hpp"

void remove_whitespaces(std::string& str);
void remove_spaces(std::string& str);

static bool bigger_than_ten(std::string& input) {
	for (std::string::iterator it = input.begin(); it != input.end(); it++) {
		if(isdigit(static_cast<int>(*it)) && *it > '0')
			if(it + 1 != input.end() && isdigit(static_cast<int>(*(it + 1))))
				return true;
	}
	return false;
}

static void validate_input(std::string& input) throw (std::invalid_argument){
	remove_whitespaces(input);
	if(input.empty())
		throw std::invalid_argument("Empty expression");
	else if (input.find_first_not_of("0123456789+-*/ ") != std::string::npos)
		throw std::invalid_argument("Invalid character in expression");
	else if (bigger_than_ten(input))
		throw std::invalid_argument("Number bigger than 10");
	remove_spaces(input);
}

int main(int argc, char **argv) {
	switch (argc) {
		case 2: {
			try {
				std::string input = argv[1];
				validate_input(input);
				RPN rpn;
				std::cout << rpn.calculate(input) << std::endl;
				break;
			}	catch (std::invalid_argument& e) {
				std::cout << e.what() << std::endl;
				return 	1;
			}	catch (std::domain_error& e) {
				std::cout << e.what() << std::endl;
				return 1;
			}	catch (std::exception& e) {
				std::cout << "Error: " << e.what() << std::endl;
				return 1;
			}
		}
		default:{
			std::cout << "Usage: " << argv[0] << " <RPN expression>" << std::endl;
			return 1;
		}
	}
	return 0;
}
