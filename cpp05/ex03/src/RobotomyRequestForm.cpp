/**======================
*            42sp
* @file      : RobotomyRequestForm.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 06/03/2024
*========================**/

#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {
	std::cout << MAGENTA << "Default RobotomyForm constructor called" << RESET << std::endl;
};

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
	std::cout << MAGENTA << "Parametric RobotomyForm constructor called" << RESET << std::endl;
};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs) : AForm("RobotomyRequestForm", 72, 45), _target(rhs._target) {
	std::cout << MAGENTA << "Copy RobotomyForm constructor called" << RESET << std::endl;
	*this = rhs;
};
RobotomyRequestForm::~RobotomyRequestForm(void){
	std::cout << RED << "RobotomyForm Destructor called" << RESET << std::endl;
};
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) {
	std::cout << MAGENTA << "Copy assignment operator called" << RESET << std::endl;
	if(this != &rhs) {
		AForm::operator=(rhs);
		const_cast<std::string&>(_target) = rhs._target;
	}
	return *this;
};

//Methods========================================================================

void RobotomyRequestForm::execute(Bureaucrat const & executor) const throw(GradeTooLowException, NotSignedException) {
	
	if(!getSigned()) {
		throw NotSignedException();
	} else if (executor.getGrade() > getGradeToExecute()) {
		throw GradeTooLowException();
	}

	srand(time(NULL));
	std::cout << "!¡!Drilling noises!¡!" << std::endl;
	if (rand() % 2) {
		std::cout << _target << " has been robotomized successfully" << std::endl;
	} else {
		std::cout << "Robotomization failed" << std::endl;
	}
};
