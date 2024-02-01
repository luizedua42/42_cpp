/**==============================================
 * ?                    ABOUT
 * @file        : Contacts.cpp
 * @author      : luizedua
 * @email       : luizedua@student.42sp.org.br
 * @createdOn   : 01/02/2024
 *=============================================**/

#include "../include/Contacts.hpp"

/*---- Class Methods -------------------------------*/

Contacts::Contacts(){}

Contacts::~Contacts(){}

void Contacts::setFirstName(std::string firstName) {
	this->_firstName = firstName;
}

std::string Contacts::getFirstName(){
	return this->_firstName;
}

void Contacts::setLastName(std::string lastName) {
	this->_lastName = lastName;
}
std::string Contacts::getLastName(){
	return this->_lastName;
}
void Contacts::setNickName(std::string nickName) {
	this->_nickName = nickName;
}
std::string Contacts::getNickName(){
	return this->_nickName;
}

void Contacts::setPhoneNumber(std::string phoneNumber) {
	this->_phoneNumber = phoneNumber;
}
std::string Contacts::getPhoneNumber(){
	return this->_phoneNumber ;
}

void Contacts::setDarkestSecret(std::string darkestSecret) {
	this->_darkestSecret = darkestSecret;
}
std::string Contacts::getDarkestSecret(){
	return this->_darkestSecret;
}


