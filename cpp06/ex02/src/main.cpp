/**======================
*            42sp
* @file      : main.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 13/03/2024
*========================**/

#include "../include/Colors.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <typeinfo>

Base* generate(void){
	int i = rand() % 3;
	switch (i){
		case 0:
			return new A();
			break;
		case 1:
			return new B();
			break;
		default:
			return new C();
	}
}

void identify(Base* p){
	if (dynamic_cast<A*>(p))
		std::cout << GREEN << "Ptr is: A" << RESET << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << GREEN << "Ptr is: B" << RESET << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << GREEN << "Ptr is: C" << RESET << std::endl;
}

void identify(Base& p){
	try{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << GREEN << "Ref is: A" << RESET << std::endl;
	}
	catch (std::bad_cast &bc){
		try{
			B &b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << GREEN << "Ref is: B" << RESET << std::endl;
		}
		catch (std::bad_cast &bc){
			try{
				C &c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << GREEN << "Ref is: C" << RESET << std::endl;
			}
			catch (std::bad_cast &bc){
				std::cout << RED << "Error: " << bc.what() << RESET << std::endl;
			}
		}
	}
}

int main(void){
	srand(time(NULL));
	for(int i = 0; i < 10; i++){
		std::cout << YELLOW << "Generating random Class ... ====================================================" << RESET << std::endl;
		Base *rndclass = generate();
		std::cout << YELLOW << "Identifying Ptr ... ============================================================" << RESET << std::endl;
		identify(rndclass);
		std::cout << YELLOW << "Identifying Ref ... ============================================================" << RESET << std::endl;
		identify(*rndclass);
		delete rndclass;
		std::cout << std::endl;
	}
	return 0;
}