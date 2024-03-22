/**======================
*            42sp
* @file      : Span.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 14/03/2024
*========================**/
#include "../include/Span.hpp"

Span::Span():  number(0), size(0){
	std::cout << "Default constructor called" << std::endl;
};

Span::Span(unsigned int n) {
	std::cout << "Parametric constructor called" << std::endl;
	this->size = n;
};

Span::Span(const Span& rhs){
	*this = rhs;
};

Span::~Span(void){
	std::cout << "Destructor called" << std::endl;
};

Span& Span::operator=(const Span& rhs) {
	if(this != &rhs) {
		for (unsigned long i = 0; i < rhs.size; i++) {
			this->number[i] = rhs.number[i];
		}
		this->size = rhs.size;
	}
	return *this;
};

std::vector<int> Span::getNumber(void){
	return this->number;
};

const char* AddFail::what() const throw() {
	return "Error: The number of elements is already at the maximum";
};

const char* LongFail::what() const throw() {
	return "Error: The number of elements is less than 2";
};

const char* ShortFail::what() const throw() {
	return "Error: The number of elements is less than 2";
};

void Span::addNumber(int n) throw (AddFail){
	if (this->size == this->number.size()) {
		throw AddFail();
	}
	this->number.push_back(n);
};

int Span::shortestSpan(void) throw (ShortFail) {
	if (this->number.size() < 2) {
		throw ShortFail();
	}
	int min = this->number[0];
	for (unsigned int i = 1; i < this->number.size(); i++) {
		if (this->number[i] < min) {
			min = this->number[i];
		}
	}
	return min;
};

int Span::longestSpan(void) throw (LongFail) {
	if (this->number.size() < 2) {
		throw LongFail();
	}
	int max = this->number[0];
	for (unsigned int i = 1; i < this->number.size(); i++) {
		if (this->number[i] > max) {
			max = this->number[i];
		}
	}
	return max;
};

//add range with iterator using addnumber
void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
throw (AddFail) {
	try{
		while (begin != end) {
			this->addNumber(*begin++);
		}
	} catch(std::exception &e){
		(void)e;
	}
};