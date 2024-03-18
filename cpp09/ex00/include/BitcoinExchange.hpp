/**======================
*            42sp
* @file      : BitcoinExchange.hpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 15/03/2024
*========================**/

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <iostream>
# include <fstream>
# include <map>
# include <cmath>
# include <stdexcept>
# include <sstream>

class BitcoinExchange {
	private:
		std::map<std::string, double> _exchange;
	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange& rhs);
		~BitcoinExchange(void);
		BitcoinExchange& operator=(const BitcoinExchange& rhs);
		void readDB(void);
		void createDB(std::string date, double value);
		void printDB(std::string date, double rate);
		double getValue(std::string date) const;
};

#endif