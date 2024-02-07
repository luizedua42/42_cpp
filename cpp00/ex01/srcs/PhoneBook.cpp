
/**==============================================
 * ?                    ABOUT
 * @file        : PhoneBook.cpp
 * @author      : luizedua
 * @email       : luizedua@student.42sp.org.br
 * @createdOn   : 01/02/2024
 *=============================================**/


#include "../include/PhoneBook.hpp"
// #include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <limits>

namespace utils {
	void clearCin(void) {
		std::cin.eof();
		fflush(stdin);
		std::clearerr(stdin);
		std::cin.clear();
	}

	bool validPhoneNbr(std::string phone) {
		if (phone.size() > 10 || phone.size() < 7)
			return (true);
		for (size_t i = 0; i < phone.size(); ++i) {
			if (i < 4 && !std::isdigit(phone[i]))
				return (true);
			else if (i > 3 && i < 6 && phone[i] != '-'
			&& !std::isdigit(phone[i]))
				return (true);
			else if (i > 6 && !std::isdigit(phone[i]))
				return (true);
		}
		return (false);
	}

	bool parseName(std::string name) {
		if (name.empty())
			return (false);
		for (std::string::iterator it = name.begin(); it != name.end(); ++it) {
			if (!isalpha(*it))
				return (false);
		}
		return (true);
	}

	bool parsePhone(std::string phone) {

		if (phone.empty() || validPhoneNbr(phone))
			return (false);
		return (true);
	}

	bool parseIndex(std::string index, size_t limit) {
		if (index.size() > 1 || index.empty()
		|| !std::isdigit(index[0]))
			return (false);
		if (limit < 8) {
			if (static_cast<size_t>(std::atol(index.c_str())) >= limit)
				return (false);
		}
		else
			if (std::atoi(index.c_str()) >= 8)
				return (false);
		return (true);
	}

	void printStartOfTable(void) {
		std::cout << "|---INDEX--|---FNAME--|--LNAME---|-NICKNAME-|"
					<< std::endl;
	}

	void printEndOfTable(void) {
		std::cout << "|----------|----------|----------|----------|"
					<< std::endl;
	}

	void printContactLine(int idx, std::string fName, std::string lName,
		std::string nName
	) {
		std::string fCopy;
		std::string lCopy;
		std::string nCopy;

		if (fName.size() > 10) {
			fCopy = fName.substr(0, 9);
			fCopy += ".";
		}
		else
			fCopy = fName;
		if (lName.size() > 10) {
			lCopy = lName.substr(0, 9);
			lCopy += ".";
		}
		else
			lCopy = lName;
		if (nName.size() > 10) {
			nCopy = nName.substr(0, 9);
			nCopy += ".";
		}
		else
			nCopy = nName;
		std::cout << "|" << std::setw(10) << idx
			<< "|" << std::setw(10) << fCopy
			<< "|" << std::setw(10) << lCopy
			<< "|" << std::setw(10) << nCopy
			<< "|" << std::endl;
	}

	void printThisContact(Contacts* contact) {
		std::cout << "First name: " << contact->getFirstName() << std::endl;
		std::cout << "Last name: " << contact->getLastName() << std::endl;
		std::cout << "Nickname: " << contact->getNickName() << std::endl;
		std::cout << "Phone number: " << contact->getPhoneNumber() << std::endl;
		std::cout << "Darkest secret: " << contact->getDarkestSecret() << std::endl;
	}
}

/*---- Class Methods -------------------------------*/

PhoneBook::PhoneBook(void){}

PhoneBook::~PhoneBook(void){}

void PhoneBook::help(void){
	std::cout << "PhoneBook Commands\n\n"
			<< "ADD: Add new contact.\n" 
			<< "SEARCH: Show all contacts.\n"
			<< "EXIT: Exit the PhoneBook.\n"
			<< "HELP: Displays this menu.\n"
			<< std::endl;
}

void PhoneBook::addContact(void) {
	std::string fName;
	std::string lName;
	std::string nName;
	std::string phoneNbr;
	std::string dSecret;

	while (true) {
		if (std::cin.eof() || std::cin.fail())
			utils::clearCin();
		std::cout << "First name: ";
		std::getline(std::cin, fName);
		if (utils::parseName(fName)) {
			utils::clearCin();
			break;
		}
		std::cout << "Invalid name." << std::endl;
		fName.clear();
	}
	utils::clearCin();
	while (true) {
		if (std::cin.eof() || std::cin.fail())
			utils::clearCin();
		std::cout << "Last name: ";
		std::getline(std::cin, lName);
		if (utils::parseName(lName)) {
			utils::clearCin();
			break;
		}
		std::cout << "Invalid name." << std::endl;
		lName.clear();
	}
	utils::clearCin();
	while (true) {
		if (std::cin.eof() || std::cin.fail())
			utils::clearCin();
		std::cout << "Nickname: ";
		std::getline(std::cin, nName);
		if (!nName.empty()) {
			utils::clearCin();
			break;
		}
		std::cout << "Invalid nickname." << std::endl;
	}
	utils::clearCin();
	while (true) {
		if (std::cin.eof() || std::cin.fail())
			utils::clearCin();
		std::cout << "Phone number: ";
		std::getline(std::cin, phoneNbr);
		if (utils::parsePhone(phoneNbr)) {
			utils::clearCin();
			break;
		}
		std::cout << "Invalid phone number." << std::endl;
		phoneNbr.clear();
	}
	utils::clearCin();
	while (true) {
		if (std::cin.eof() || std::cin.fail())
			utils::clearCin();
		std::cout << "Your darkest secret: ";
		std::getline(std::cin, dSecret);
		if (!dSecret.empty()) {
			utils::clearCin();
			break;
		}
		std::cout << "Invalid secret." << std::endl;
	}
	this->_contacts[this->_nbrOfContacts % 8].setFirstName(fName);
	this->_contacts[this->_nbrOfContacts % 8].setLastName(lName);
	this->_contacts[this->_nbrOfContacts % 8].setNickName(nName);
	this->_contacts[this->_nbrOfContacts % 8].setPhoneNumber(phoneNbr);
	this->_contacts[this->_nbrOfContacts % 8].setDarkestSecret(dSecret);
	this->_nbrOfContacts++;
}

void PhoneBook::searchContact(void) {
	if (this->_nbrOfContacts == 0) {
		std::cout << "Your contact list is empty." <<
			std::endl;
		return;
	}

	utils::printStartOfTable();
	if (this->_nbrOfContacts < 8) {
		for (size_t i = 0; i < this->_nbrOfContacts; ++i) {
			utils::printContactLine(i,
				this->_contacts[i].getFirstName(),
				this->_contacts[i].getLastName(),
				this->_contacts[i].getNickName()
			);
		}
	}
	else {
		for (size_t i = 0; i < 8; ++i) {
			utils::printContactLine(i,
				this->_contacts[i].getFirstName(),
				this->_contacts[i].getLastName(),
				this->_contacts[i].getNickName()
			);
		}
	}
	utils::printEndOfTable();

	std::string idx;

	while (true) {
		if (std::cin.eof() || std::cin.fail())
			utils::clearCin();
		std::cout << "Select an index: ";
		std::getline(std::cin, idx);
		if (utils::parseIndex(idx, this->_nbrOfContacts))
			break;
		std::cout << "Invalid index." << std::endl;
	}
	utils::clearCin();
	utils::printThisContact(&this->_contacts[std::atoi(idx.c_str())]);
}

size_t PhoneBook::_nbrOfContacts = 0;