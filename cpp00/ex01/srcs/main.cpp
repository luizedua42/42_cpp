/**==============================================
 * ?                    ABOUT
 * @file        : main.cpp
 * @author      : luizedua
 * @email       : luizedua@student.42sp.org.br
 * @createdOn   : 01/02/2024
 *=============================================**/

#include "../include/PhoneBook.hpp"
#include "../include/Contacts.hpp"
// #include <iostream>
// #include <string>

int main(void){
	PhoneBook agenda;
	std::string cmd;
	do {
		// if (std::cin.eof() || std::cin.fail())
		// 	utils::clearCin();
		std::cout << "PhoneBook> ";
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
			agenda.addContact();
		else if (cmd == "SEARCH")
			agenda.searchContact();
		else 
		if (cmd == "HELP")
			agenda.help();
		else if (cmd != "EXIT")
			std::cout << "Invalid command." << std::endl;
	} while (cmd != "EXIT");
	return 0;
}