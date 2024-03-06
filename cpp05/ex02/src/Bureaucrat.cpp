/**======================
*            42sp
* @file      : Bureaucrat.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 06/03/2024
*========================**/

#include "../include/Bureaucrat.hpp"

// Constructor & Destructor ===================================================

Bureaucrat::Bureaucrat() {
	std::cout << GREEN << "Default constructor called" << RESET << std::endl;
	const_cast<std::string&>(_name) = "John Deux";
	_grade = rand() % 150 + 1;
};

Bureaucrat::Bureaucrat(std::string const name, int grade)
throw(GradeTooHighException, GradeTooLowException):
_name(name), _grade(grade)
{
	std::cout << MAGENTA << "Parametric constructor called" << RESET << std::endl;
	if (grade < 1) {
		throw GradeTooHighException();
	} else if (grade > 150) {
		throw GradeTooLowException();
	}
	_grade = grade;
};

Bureaucrat::Bureaucrat(const Bureaucrat& rhs){
	std::cout << MAGENTA << "Copy constructor called" << RESET << std::endl;
	*this = rhs;
};

Bureaucrat::~Bureaucrat(void){
	std::cout << RED << "Destructor called" << RESET << std::endl;
};



// Methods ====================================================================

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high it needs to be between 1 and 150";
};

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low it needs to be between 1 and 150";
};

const std::string Bureaucrat::getName(void) const {
	return _name;
};

void Bureaucrat::setName(std::string const name) {
	const_cast<std::string&>(_name) = name;
};


int Bureaucrat::getGrade(void) const{
	return _grade;
};

void Bureaucrat::increaseGrade(void) {
	if (_grade - 1 < 1) {
		throw GradeTooHighException();
	}
	_grade--;
};

void Bureaucrat::decreaseGrade(void) {
	if (_grade + 1 > 150) {
		throw GradeTooLowException();
	}
	_grade++;
};

void Bureaucrat::executeForm(AForm const & form) {
	try {
		form.execute(*this);
		std::cout << GREEN << _name << " executes " << form.getName() << RESET << std::endl;
	} catch (std::exception & e) {
		std::cout << RED << _name << " cannot execute " << form.getName() << " because " << e.what() << RESET << std::endl;
	}

};
// Operators ==================================================================

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs){
	if(this != &rhs) {
		const_cast<std::string&>(this->_name) = rhs.getName();
		this->_grade = rhs.getGrade();
	}
	return *this;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs) {
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return os;
};


