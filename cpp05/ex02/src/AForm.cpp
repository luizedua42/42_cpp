/**======================
*            42sp
* @file      : AForm.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 06/03/2024
*========================**/

#include "../include/AForm.hpp"

// Exceptions====================================================================
const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade too high";
};

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade too low";
};

const char* AForm::NotSignedException::what() const throw() {
	return "Form not signed";
};

// Constructors&Destructors=====================================================

AForm::AForm(): _name("Default AForm"), _gradeToSign(150), _gradeToExecute(150){
	std::cout << GREEN << "Default constructor called" << RESET << std::endl;
	const_cast<int&>(_gradeToSign) = rand() % 150 + 1;
	const_cast<int&>(_gradeToExecute) = rand() % 150 + 1;
	_signed = false;	
};

AForm::AForm(std::string const name, int gradeToSign, int gradeToExecute)
throw(GradeTooHighException, GradeTooLowException): 
_name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _signed(false){
	std::cout << MAGENTA << "Parametric constructor called" << RESET << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1) {
		throw GradeTooHighException();	
	} else if (gradeToSign > 150 || gradeToExecute > 150) {
		throw GradeTooLowException();
	}
};

AForm::AForm(const AForm& rhs): _name(rhs._name), _gradeToSign(rhs._gradeToSign), _gradeToExecute(rhs._gradeToExecute){
	std::cout << MAGENTA << "Copy constructor called" << RESET << std::endl;
	_signed = rhs._signed;
	*this = rhs;
};

AForm::~AForm(void){
	std::cout << RED << "Destructor called" << RESET << std::endl;
};



// Methods=======================================================================

void AForm::beSigned(const Bureaucrat& rhs)
throw(GradeTooLowException) {
	if (rhs.getGrade() <= _gradeToSign) {
		_signed = true;
	} else {
		throw AForm::GradeTooLowException();
	}
};

void AForm::signAForm(void) {
	if (_signed) {
		std::cout << GREEN << "AForm " << _name << " signed" << RESET << std::endl;
	} else {
		std::cout << RED << "AForm " << _name << " not signed" << RESET << std::endl;
	}
};

const std::string AForm::getName(void) const {
	return _name;
};

bool AForm::getSigned(void) const {
	return _signed;
};

int AForm::getGradeToSign(void) const {
	return _gradeToSign;
};

int AForm::getGradeToExecute(void) const {
	return _gradeToExecute;
};

void AForm::execute(Bureaucrat const & executor) const
throw(GradeTooLowException, NotSignedException) {
	if (!_signed) {
		throw AForm::NotSignedException();
	} else if (executor.getGrade() > _gradeToExecute) {
		throw AForm::GradeTooLowException();
	}
};

// Operators=====================================================================

AForm& AForm::operator=(const AForm& rhs){
	std::cout << MAGENTA << "Copy assignment operator called" << RESET << std::endl;
	const_cast<std::string&>(_name) = rhs.getName();
	const_cast<int&>(_gradeToSign) = rhs.getGradeToSign();
	const_cast<int&>(_gradeToExecute) = rhs.getGradeToExecute();
	_signed = rhs._signed;

	return *this;
};

std::ostream& operator<<(std::ostream& os, const AForm& rhs) {
	os << "AForm " << rhs.getName() << " is ";
	if (rhs.getSigned() == true) {
		os << "signed";
	} else {
		os << "not signed" << " and requires grade " << rhs.getGradeToSign()
		<< " to sign and grade " << rhs.getGradeToExecute() << " to execute";
	}
	return os;
};
