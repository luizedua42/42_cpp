/**======================
*            42sp
* @file      : Intern.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 07/03/2024
*========================**/

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
	std::cout << MAGENTA << "Intern default constructor called" << RESET << std::endl;
}
Intern::Intern(const Intern& rhs){
	std::cout << MAGENTA << "Copy constructor called" << RESET << std::endl;
	*this = rhs;
};
Intern::~Intern(void){
	std::cout << RED << "Intern destructor called" << RESET << std::endl;
};

AForm* Intern::makeForm(std::string formName, std::string target) const {
	std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	for (int i = 0; i < 3; i++) {
		if (formName == formNames[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			switch (i) {
				case 0:
					return new ShrubberyCreationForm(target);
				case 1:
					return new RobotomyRequestForm(target);
				case 2:
					return new PresidentialPardonForm(target);
			}
		}
	}
	std::cout << "Form not found" << std::endl;
	return NULL;
};

Intern& Intern::operator=(const Intern& rhs) {
	std::cout << MAGENTA << "Copy assignment operator called" << RESET << std::endl;
	(void)rhs;
	return *this;
};

