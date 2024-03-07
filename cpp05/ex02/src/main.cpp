/**======================
*            42sp
* @file      : main.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 06/03/2024
*========================**/

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"


namespace tests {
	void robotomy(void)
	{
		std::cout << YELLOW << "Robotomy =========================================================" << RESET << std::endl;
		Bureaucrat john("John", 1);
		Bureaucrat jane("Jane", 150);
		RobotomyRequestForm robotomy("Ajax1");
		john.signForm(robotomy);
		john.executeForm(robotomy);
		jane.signForm(robotomy);
		jane.executeForm(robotomy);
	}
	void robotomyCopy(void)
	{
		std::cout << YELLOW << "RobotoCopy =======================================================" << RESET << std::endl;
		Bureaucrat john("John", 1);
		Bureaucrat jane("Jane", 1);
		RobotomyRequestForm robotomy("Ajax2");
		RobotomyRequestForm robotomyCopy(robotomy);
		john.signForm(robotomyCopy);
		john.executeForm(robotomy);
		john.executeForm(robotomyCopy);
		jane.executeForm(robotomyCopy);
		jane.executeForm(robotomy);
	}
	void presidential(void)
	{
		std::cout << YELLOW << "Presidential =======================================================" << RESET << std::endl;
		Bureaucrat john("John", 1);
		Bureaucrat jane("Jane", 150);
		PresidentialPardonForm presidential("Kiko1");
		john.signForm(presidential);
		john.executeForm(presidential);
		jane.signForm(presidential);
		jane.executeForm(presidential);
	}
	void presidentialCopy(void)
	{
		std::cout << YELLOW << "PresidentialCopy ===================================================" << RESET << std::endl;
		Bureaucrat john("John", 1);
		Bureaucrat jane("Jane", 1);
		PresidentialPardonForm presidential("Kiko2");
		PresidentialPardonForm presidentialCopy(presidential);
		john.signForm(presidentialCopy);
		john.executeForm(presidential);
		john.executeForm(presidentialCopy);
		jane.executeForm(presidentialCopy);
		jane.executeForm(presidential);
	}
	void shrubbery(void)
	{
		std::cout << YELLOW << "Shrubbery =========================================================" << RESET << std::endl;
		Bureaucrat john("John", 1);
		Bureaucrat jane("Jane", 150);
		ShrubberyCreationForm shrubbery("Shrubbery1");
		john.signForm(shrubbery);
		john.executeForm(shrubbery);
		jane.signForm(shrubbery);
		jane.executeForm(shrubbery);
	}
	void shrubberyCopy(void)
	{
		std::cout << YELLOW << "ShrubberyCopy =====================================================" << RESET << std::endl;
		Bureaucrat john("John", 1);
		Bureaucrat jane("Jane", 1);
		ShrubberyCreationForm shrubbery("Shrubbery2");
		ShrubberyCreationForm shrubberyCopy(shrubbery);
		john.signForm(shrubberyCopy);
		john.executeForm(shrubbery);
		john.executeForm(shrubberyCopy);
		jane.executeForm(shrubberyCopy);
		jane.executeForm(shrubbery);
	}
};

int main() {
	tests::robotomy();
	tests::robotomyCopy();
	tests::presidential();
	tests::presidentialCopy();
	tests::shrubbery();
	tests::shrubberyCopy();
	return 0;
}
