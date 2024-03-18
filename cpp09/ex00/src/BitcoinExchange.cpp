/**======================
*            42sp
* @file      : BitcoinExchange.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 18/03/2024
*========================**/

#include "../include/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& rhs){
	*this = rhs;
}

BitcoinExchange::~BitcoinExchange(void){}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs) {
	if(this != &rhs)
		_exchange = rhs._exchange;
	return *this;
}



void BitcoinExchange::readDB(void) {
	
	std::ifstream db;
	std::string line;
	double value;

	db.open("./data.csv");
	if(!db.is_open()) {
		throw std::invalid_argument("File not found");
	}

	std::getline(db, line);
	if(line != "date,exchange_rate") {
		throw std::invalid_argument("Invalid dB format");
	}

	while(getline(db, line)) {
		std::string date = line.substr(0, line.find(","));
		std::istringstream iss(line.substr(line.find(",")+1, line.length()));
		iss >> value;
		createDB(date, value);
	}

}

void BitcoinExchange::createDB(std::string date, double value) {
	_exchange[date] = value;
}

void BitcoinExchange::printDB(void) {
	for(std::map<std::string, double>::iterator it = _exchange.begin(); it != _exchange.end(); it++) {
		std::cout << it->first << " | " << it->second << std::endl;
	}
}

double BitcoinExchange::getValue(std::string date) const {
	//find date in map, if not found, find closest date before it and return that value
	std::map<std::string, double>::const_iterator it = _exchange.find(date);
	if(it != _exchange.end()) {
		return it->second;
	}
	else {
		std::map<std::string, double>::const_iterator it = _exchange.lower_bound(date);
		if(it == _exchange.begin()) {
			throw std::invalid_argument("Date not found");
		}
		it--;
		return it->second;
	}
}