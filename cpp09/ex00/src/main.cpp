/**======================
*            42sp
* @file      : main.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 18/03/2024
*========================**/

#include "../include/BitcoinExchange.hpp"
#include <iostream>

int main(void) {
	BitcoinExchange exchange;
	exchange.readDB();
	exchange.printDB();
	return 0;
}