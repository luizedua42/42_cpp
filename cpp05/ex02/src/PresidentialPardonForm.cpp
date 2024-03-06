/**======================
*            42sp
* @file      : PresidentialPardonForm.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 06/03/2024
*========================**/

#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) {
	std::cout << "Default PresidentialPardonForm constructor called" << std::endl;
};

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : AForm("PresidentialPardonForm", 25, 5), _target(target){
	std::cout << "Parametric PresidentialPardonForm constructor called" << std::endl;
};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& rhs) : AForm("PresidentialPardonForm", 25, 5), _target(rhs._target) {
	std::cout << "Copy PresidentialPardonForm constructor called" << std::endl;
	*this = rhs;
};

PresidentialPardonForm::~PresidentialPardonForm(void){
	std::cout << "PresidentialPardonForm Destructor called" << std::endl;
};

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
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

