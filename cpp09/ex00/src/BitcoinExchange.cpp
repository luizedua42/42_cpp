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

bool isValidDate(std::string date) {
	if(date.length() != 10) {
		return false;
	}
	else if(date.substr(4,1) != "-" || date.substr(7,1) != "-") {
		return false;
	}
	else if(date.substr(0,4) < "2000" || date.substr(0,4) > "2024") {
		return false;
	}
	else if(date.substr(5,2) < "01" || date.substr(5,2) > "12") {
		return false;
	}
	else if(date.substr(8,2) < "01" || date.substr(8,2) > "31") {
		return false;
	}
	return true;
}
void BitcoinExchange::printDB(std::string date, double rate) {
	if (!isValidDate(date)) {
		std::cout << "Error: bad input => " << date << std::endl;
		return;
	}

	double result = getValue(date) * rate;
	
	if (result < 0)
		std::cout << "Error: not a positive number." << std::endl;
	else
		std::cout << date << " => " << result << std::endl;
}

double BitcoinExchange::getValue(std::string date) const {
	std::map<std::string, double>::const_iterator it = _exchange.lower_bound(date);
	if(it == _exchange.begin() && it->first != date) {
		return 0;
	}
	if(it != _exchange.begin() && it->first != date) {
		return (--it)->second;
	}
	return it->second;
}