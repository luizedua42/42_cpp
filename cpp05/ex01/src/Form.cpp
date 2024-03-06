/**======================
*            42sp
* @file      : Form.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 06/03/2024
*========================**/

#include "../include/Form.hpp"

// Exceptions====================================================================
const char* Form::GradeTooHighException::what() const throw() {
	return "Grade too high";
};

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade too low";
};

// Constructors&Destructors=====================================================

Form::Form(): _name("Default Form"), _gradeToSign(150), _gradeToExecute(150){
	std::cout << GREEN << "Default constructor called" << RESET << std::endl;
	const_cast<int&>(_gradeToSign) = rand() % 150 + 1;
	const_cast<int&>(_gradeToExecute) = rand() % 150 + 1;
	_signed = false;	
};

Form::Form(std::string const name, int gradeToSign, int gradeToExecute)
throw(GradeTooHighException, GradeTooLowException): 
_name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _signed(false){
	std::cout << MAGENTA << "Parametric constructor called" << RESET << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1) {
		throw GradeTooHighException();	
	} else if (gradeToSign > 150 || gradeToExecute > 150) {
		throw GradeTooLowException();
	}
};

Form::Form(const Form& rhs): _name(rhs._name), _gradeToSign(rhs._gradeToSign), _gradeToExecute(rhs._gradeToExecute){
	std::cout << MAGENTA << "Copy constructor called" << RESET << std::endl;
	_signed = rhs._signed;
	*this = rhs;
};

Form::~Form(void){
	std::cout << RED << "Destructor called" << RESET << std::endl;
};



// Methods=======================================================================

void Form::beSigned(const Bureaucrat& rhs) {
	if (rhs.getGrade() <= _gradeToSign) {
		_signed = true;
	} else {
		throw Form::GradeTooLowException();
	}
};

void Form::signForm(void) {
	if (_signed) {
		std::cout << GREEN << "Form " << _name << " signed" << RESET << std::endl;
	} else {
		std::cout << RED << "Form " << _name << " not signed" << RESET << std::endl;
	}
};

const std::string Form::getName(void) const {
	return _name;
};

bool Form::getSigned(void) const {
	return _signed;
};

int Form::getGradeToSign(void) const {
	return _gradeToSign;
};

int Form::getGradeToExecute(void) const {
	return _gradeToExecute;
};



// Operators=====================================================================

Form& Form::operator=(const Form& rhs){
	std::cout << MAGENTA << "Copy assignment operator called" << RESET << std::endl;
	const_cast<std::string&>(_name) = rhs.getName();
	const_cast<int&>(_gradeToSign) = rhs.getGradeToSign();
	const_cast<int&>(_gradeToExecute) = rhs.getGradeToExecute();
	_signed = rhs._signed;

	return *this;
};

std::ostream& operator<<(std::ostream& os, const Form& rhs) {
	os << "Form " << rhs.getName() << " is ";
	if (rhs.getSigned() == true) {
		os << "signed";
	} else {
		os << "not signed" << " and requires grade " << rhs.getGradeToSign()
		<< " to sign and grade " << rhs.getGradeToExecute() << " to execute";
	}
	return os;
};
