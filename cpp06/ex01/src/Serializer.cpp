/**======================
*            42sp
* @file      : Serialiazer.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 12/03/2024
*========================**/


#include "../include/Serializer.hpp"

Serializer::Serializer() {
	std::cout << MAGENTA <<  "Default constructor called" << RESET << std::endl;
}
Serializer::Serializer(const Serializer& rhs){
	std::cout << MAGENTA <<  "Copy constructor called" << RESET << std::endl;
	*this = rhs;
};
Serializer::~Serializer(void){
	std::cout << RED <<  "Destructor called" << RESET << std::endl;
};
Serializer& Serializer::operator=(const Serializer& rhs) {
	std::cout << MAGENTA <<  "Copy assignment operator called" << RESET << std::endl;
	(void)rhs;
	return *this;
};

uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}
