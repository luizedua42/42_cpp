/**======================
*            42sp
* @file      : Data.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 12/03/2024
*========================**/

# include "../include/Data.hpp"

Data::Data(): _data(0){
	std::cout << MAGENTA << "Default constructor called" << RESET << std::endl;
}
Data::Data(const Data& rhs){
	std::cout << MAGENTA << "Copy constructor called" << RESET << std::endl;
	*this = rhs;
};
Data::~Data(void){
	std::cout << RED << "Destructor called" << RESET << std::endl;
};
Data& Data::operator=(const Data& rhs) {
	std::cout << MAGENTA << "Copy assignment operator called" << RESET << std::endl;
	if(this != &rhs)
		_data = rhs._data;
	return *this;
};

uint32_t Data::getData(void) const {
	return _data;
}

void Data::setData(uint32_t data) {
	_data = data;
}
