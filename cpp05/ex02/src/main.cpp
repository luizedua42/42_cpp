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
	void validRobotomyTest() {
		Bureaucrat b("Bureaucrat", 1);
		RobotomyRequestForm r("Target");
		try {
			r.beSigned(b);
			b.executeForm(r);
		} catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
};

int main() {
	tests::validRobotomyTest();
	return 0;
}
