/**======================
*            42sp
* @file      : Brain.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 04/03/2024
*========================**/

#include "../include/Brain.hpp"

Brain::Brain() {
	std::cout <<"Brain default constuctor" << std::endl;
	for (unsigned int i = 0; i < 100; i++) {
		_ideas[i] = "Lick";
	}
};

Brain::Brain(const Brain& rhs){
	std::cout << "Brain copy constructor" << std::endl;
	*this = rhs;
};

Brain::~Brain(void){
	std::cout << RED << "Brain default destructor" << RESET << std::endl;
};

Brain& Brain::operator=(const Brain& rhs) {
	std::cout << "Brain copy operator" << std::endl;
	if(this != &rhs) {
		for (unsigned int i = 0; i < 100; i++){
			setIdea(i, rhs._ideas[i]);
		}
	}
	return *this;
};

void Brain::setIdea(unsigned int i, std::string idea) {
	if (i < 100)
		this->_ideas[i] = idea;
	else
		std::cout << "Idea index out of range" << std::endl;
};

std::string Brain::getIdea(unsigned int i) const {
	return this->_ideas[i];
};	