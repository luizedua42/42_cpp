/**==============================================
 * ?                    ABOUT
 * @file        : Contacts.hpp
 * @author      : luizedua
 * @email       : luizedua@student.42sp.org.br
 * @createdOn   : 01/02/2024
 *=============================================**/

#ifndef CONTACTS_HPP
# define CONTACTS_HPP

# include <iostream>
# include <string>

class Contacts {
	private:
		std::string	_phoneNumber;
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_darkestSecret;
	public:
		Contacts();
		~Contacts();
		void setFirstName(std::string firstName);
		void setLastName(std::string lastName);
		void setNickName(std::string nickName);
		void setPhoneNumber(std::string phoneNumber);
		void setDarkestSecret(std::string darkestSecret);
		std::string getFirstName();
		std::string getLastName();
		std::string getNickName();
		std::string getPhoneNumber();
		std::string getDarkestSecret();
};

#endif