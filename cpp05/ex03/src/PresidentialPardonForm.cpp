/**======================
*            42sp
* @file      : PresidentialPardonForm.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 06/03/2024
*========================**/

#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) {
	std::cout << MAGENTA << "Default PresidentialPardonForm constructor called" << RESET << std::endl;
};

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : AForm("PresidentialPardonForm", 25, 5), _target(target){
	std::cout << MAGENTA << "Parametric PresidentialPardonForm constructor called" << RESET << std::endl;
};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& rhs) : AForm("PresidentialPardonForm", 25, 5), _target(rhs._target) {
	std::cout << MAGENTA << "Copy PresidentialPardonForm constructor called" << RESET << std::endl;
	*this = rhs;
};

PresidentialPardonForm::~PresidentialPardonForm(void){
	std::cout << RED << "PresidentialPardonForm Destructor called" << RESET << std::endl;
};

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs) {
	std::cout << MAGENTA << "Copy assignment operator called" << RESET << std::endl;
	if(this != &rhs) {
		AForm::operator=(rhs);
		const_cast<std::string&>(_target) = rhs._target;
	}
	return *this;
};

//Methods========================================================================

void PresidentialPardonForm::execute(Bureaucrat const & executor) const 
throw(GradeTooLowException, NotSignedException) {
	if (this->getSigned() == false) {
		throw NotSignedException();
	} else if (executor.getGrade() > this->getGradeToExecute()) {
		throw GradeTooLowException();
	}
	std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
};

