/**======================
*            42sp
* @file      : main.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 06/03/2024
*========================**/

#include "../include/Bureaucrat.hpp"

namespace tests {
	void DefaultTest(void) {
		std::cout<< YELLOW << "Default class tests ========================" << RESET << std::endl;
		try {
			Bureaucrat b1;
			std::cout << b1 << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	void BureaucratTest(void) {
		std::cout << YELLOW << "Parametric class tests ====================" << RESET << std::endl;
		try {
			Bureaucrat b1("Luiz", 1);
			std::cout << b1 << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	void operatorTest(void) {
		std::cout << YELLOW << "Operator class tests =======================" << RESET << std::endl;
		try {
			Bureaucrat b1("Blaine", 1);
			std::cout << b1 << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	void increaseDecreaseTest(void) {
		std::cout << YELLOW << "Increase/Decrease class tests ==============" << RESET << std::endl;
		try {
			Bureaucrat b1("Luiz", rand() % 150 + 1);
			std::cout << b1 << std::endl;
			std::cout << "Increasing grade" << std::endl;
			b1.increaseGrade();
			std::cout << b1 << std::endl;
			std::cout << "Decreasing grade" << std::endl;
			b1.decreaseGrade();
			std::cout << b1 << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	void copyTest(void) {
		std::cout << YELLOW << "Copy class tests ===========================" << RESET << std::endl;
		try {
			Bureaucrat b1("Luiz", 1);
			std::cout << "Bureaucrat 1: " <<b1 << std::endl;
			std::cout << "Bureaucrat 1 address: " << &b1 << std::endl;
			Bureaucrat b2(b1);
			std::cout << "Bureaucrat 2: " << b2 << std::endl;
			std::cout << "Bureaucrat 2 address: " << &b2 << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	void exceptionTest(void) {
		std::cout << YELLOW << "Exception class tests ======================" << RESET << std::endl;
		try {
			std::cout << "Grade 0 Bureaucrat" << std::endl;
			Bureaucrat b1("Luiz", 0);
			std::cout << b1 << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			std::cout << "Grade 151 Bureaucrat" << std::endl;
			Bureaucrat b1("Luiz", 151);
			std::cout << b1 << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}


}


int main(void) {
	std::cout << GREEN << "==============Bureaucrat tests==============" << RESET << std::endl;
	tests::DefaultTest();
	tests::BureaucratTest();
	tests::operatorTest();
	tests::increaseDecreaseTest();
	tests::copyTest();
	tests::exceptionTest();

	return 0;
}