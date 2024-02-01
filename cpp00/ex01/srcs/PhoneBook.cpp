
/**==============================================
 * ?                    ABOUT
 * @file        : PhoneBook.cpp
 * @author      : luizedua
 * @email       : luizedua@student.42sp.org.br
 * @createdOn   : 01/02/2024
 *=============================================**/


#include "../include/PhoneBook.hpp"


namespace print {
	void guide(){
		std::string  option;
		std::cout << "Crappy PhoneBook\n\n"
				<< "ADD: Add new contact.\n" 
				<< "SEARCH: Show all contacts.\n"
				<< "EXIT: Exit the PhoneBook.\n"
				<< std::endl;
	}
};

/*---- Class Methods -------------------------------*/

PhoneBook::PhoneBook(void){}

PhoneBook::~PhoneBook(void){}
