/**======================
*            42sp
* @file      : main.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 18/03/2024
*========================**/

#include "../include/BitcoinExchange.hpp"
#include <iostream>

void execInput(std::string input, BitcoinExchange& exchange){

	std::ifstream file;
	std::string line;
	std::string date;
	double rate;

	file.open(input.c_str());
	if(!file.is_open()) {
		throw std::invalid_argument("File not found");
	}

	std::getline(file, line);
	if(line != "date | value") {
		throw std::invalid_argument("Invalid input format");
	}
	
	while(getline(file, line)) {
		date = line.substr(0, line.find(" | "));
		std::istringstream iss(line.substr(line.find(" | ")+3, line.length()));
		iss >> rate;
		if (rate > 1000)
			std::cout << "Error: too large a number" << std::endl;
		else
			exchange.printDB(date, rate);
	}
}
int main(int argc, char **argv) {
	if(argc != 2) {
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}
	BitcoinExchange exchange;
	try{
		exchange.readDB();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
	try{
		execInput(argv[1], exchange);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}