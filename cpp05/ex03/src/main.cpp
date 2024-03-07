/**======================
*            42sp
* @file      : main.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 06/03/2024
*========================**/

#include "Intern.hpp"

namespace test {
	void testIntern() {
		std::cout << YELLOW << "Good Intern test =====================================================" << RESET << std::endl;
		Intern Alex_Rider;
		AForm* form1 = Alex_Rider.makeForm("shrubbery creation", "Homer");
		AForm* form2 = Alex_Rider.makeForm("robotomy request", "Bender");
		AForm* form3 = Alex_Rider.makeForm("presidential pardon", "John Deux");
		Bureaucrat bureaucrat("Flynn", 1);

		bureaucrat.signForm(*form1);
		bureaucrat.executeForm(*form1);
		bureaucrat.signForm(*form2);
		bureaucrat.executeForm(*form2);
		bureaucrat.signForm(*form3);
		bureaucrat.executeForm(*form3);

		delete form1;
		delete form2;
		delete form3;

	}
	void testInternFail() {
		std::cout << std::endl;
		std::cout << YELLOW << "Bad Intern test ======================================================" << RESET << std::endl;
		Intern Alex_Rider;
		Bureaucrat bureaucrat("Olivia", 1);
		AForm* form1 = Alex_Rider.makeForm("free brains", "Blaine Deux");

		if(form1)
			std::cout << MAGENTA << "Wait what?" << RESET << std::endl;
		else
			std::cout << MAGENTA << "Form not found" << RESET << std::endl;
	}
}

int main() {
	test::testIntern();
	test::testInternFail();
	return 0;
}
