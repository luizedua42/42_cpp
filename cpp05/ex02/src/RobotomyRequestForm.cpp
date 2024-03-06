/**======================
*            42sp
* @file      : RobotomyRequestForm.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 06/03/2024
*========================**/

#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {
	std::cout << "Default RobotomyForm constructor called" << std::endl;
};

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
	std::cout << "Parametric RobotomyForm constructor called" << std::endl;
};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs) : AForm("RobotomyRequestForm", 72, 45), _target(rhs._target) {
	std::cout << "Copy RobotomyForm constructor called" << std::endl;
	*this = rhs;
};
RobotomyRequestForm::~RobotomyRequestForm(void){
	std::cout << "RobotomyForm Destructor called" << std::endl;
};
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &rhs) {
		AForm::operator=(rhs);
		const_cast<std::string&>(_target) = rhs._target;
	}
	return *this;
};

//Methods========================================================================

void RobotomyRequestForm::execute(Bureaucrat const & executor) const throw(GradeTooLowException, NotSignedException) {
	AForm::execute(executor);
	std::cout << "!¡!Drilling noises!¡!" << std::endl;
	if (rand() % 2 == 0) {
		std::cout << _target << " has been robotomized successfully" << std::endl;
	} else {
		std::cout << "Robotomization failed" << std::endl;
	}
};
