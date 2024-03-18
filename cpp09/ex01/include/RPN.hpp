/**======================
*            42sp
* @file      : RPN.hpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 15/03/2024
*========================**/

#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>
# include <stack>
# include <exception>
# include <cstdlib>

class RPN {
	private:
		std::stack<int> _stack;
	public:
		RPN(void);
		RPN(const RPN& rhs);
		~RPN(void);
		RPN& operator=(const RPN& rhs);
		ssize_t calculate(std::string expr) throw(std::domain_error);
};

#endif
