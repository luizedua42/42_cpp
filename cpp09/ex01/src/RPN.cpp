/**======================
*            42sp
* @file      : RPN.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 15/03/2024
*========================**/

#include "../include/RPN.hpp"
#include <sstream>
RPN::RPN() {}

RPN::RPN(const RPN& rhs){
	*this = rhs;
};

RPN::~RPN(void){};

RPN& RPN::operator=(const RPN& rhs) {
	static_cast<void>(rhs);
	return *this;
};



static void do_the_math(std::stack<ssize_t>& stack, char op) throw(std::domain_error){
	ssize_t a, b = 0;

	if(stack.size() < 2)
		throw std::domain_error("Invalid expression: there are not enough numbers in the stack.");
	b = stack.top();
	stack.pop();
	a = stack.top();
	stack.pop();

	switch(op) {
		case '+':
			stack.push(a + b);
			break;
		case '-':
			stack.push(a - b);
			break;
		case '*':
			stack.push(a * b);
			break;
		case '/':
			b == 0 ? throw std::domain_error("Division by zero") : stack.push(	a / b);
			break;
	}
}

ssize_t RPN::calculate(std::string expr) throw(std::domain_error){
	std::stack<ssize_t> stack;

	for(std::string::iterator it = expr.begin(); it != expr.end(); it++) {
		if(isdigit(static_cast<int>(*it)))
			stack.push(static_cast<int>(*it) - '0');
		else
			do_the_math(stack, *it);
	}
	if(stack.size() != 1)
		throw std::domain_error("Invalid expression: there are numbers left in the stack.");
	return stack.top();
}