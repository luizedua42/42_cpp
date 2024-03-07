/**======================
*            42sp
* @file      : main.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 06/03/2024
*========================**/

#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

namespace tests {
	void defaultFormTest(void) {
		std::cout << YELLOW << "Default Form Test ======================================================================" << RESET << std::endl;
		try {
			Form f1;
			std::cout << f1 << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	void parametricFormTest(void) {
		std::cout << YELLOW << "Parametric Form Test ===================================================================" << RESET << std::endl;
		try {
			Form f1("Form 1", 1, 1);
			std::cout << f1 << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	void invalidParametricFormTest(void) {
		std::cout << YELLOW << "Invalid Parametric Form Test ===========================================================" << RESET << std::endl;
		std::cout << "Grades are 0" << std::endl;
		try {
			Form f1("Form G0", 0, 0);
			std::cout << f1 << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << "Grades are 151" << std::endl;
		try {
			Form f2("Form G151", 151, 151);
			std::cout << f2 << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	
	}
	void copyFormTest(void) {
		std::cout << YELLOW << "Copy Form Test =========================================================================" << RESET << std::endl;
		try {
			Form f1("Form 1", 1, 1);
			std::cout << "Form 1: " << f1 << std::endl;
			std::cout << "Form 1 address: " << &f1 << std::endl;
			Form f2(f1);
			std::cout << "Form 2: " << f2 << std::endl;
			std::cout << "Form 2 address: " << &f2 << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	void signFormTest(void) {
		std::cout << YELLOW << "Sign Form Test =========================================================================" << RESET << std::endl;
		std::cout << "Bureaucrat can sign" << std::endl;
			try {
				Form f1("Form 1", 1, 1);
				std::cout << f1 << std::endl;
				Bureaucrat b1("Luiz", 1);
				std::cout << b1 << std::endl;
				std::cout << "Bureaucrat is trying to sign" << std::endl;
				b1.signForm(f1);
			} catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}
	}
	void invalidSignFormTest(void) {
		std::cout << YELLOW << "Invalid Sign Form Test =================================================================" << RESET << std::endl;
		std::cout << "Bureaucrat can't sign" << std::endl;
			Form f1("Form 1", 1, 1);
			std::cout << f1 << std::endl;
			Bureaucrat b1("Luiz", 150);
			std::cout << b1 << std::endl;
			std::cout << "Bureaucrat is trying to sign" << std::endl;
		try {
			b1.signForm(f1);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << f1 << std::endl;
	}

}


int main(void) {
	std::cout << GREEN << "=======================================Form tests=======================================" << RESET << std::endl;
	std::cout << std::endl;
	tests::defaultFormTest();
	std::cout << std::endl;
	tests::parametricFormTest();
	std::cout << std::endl;
	tests::invalidParametricFormTest();
	std::cout << std::endl;
	tests::copyFormTest();
	std::cout << std::endl;
	tests::signFormTest();
	std::cout << std::endl;
	tests::invalidSignFormTest();
	return 0;
}