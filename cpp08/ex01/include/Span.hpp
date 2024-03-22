/**======================
*            42sp
* @file      : Span.hpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 14/03/2024
*========================**/
#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <vector>
# include <exception>

class AddFail: public std::exception {
	public:
		virtual const char* what() const throw();
};

class LongFail: public std::exception {
	public:
		virtual const char* what() const throw();
};

class ShortFail: public std::exception {
	public:
		virtual const char* what() const throw();
};

class Span {
	private:
		std::vector<int>	number;
		unsigned long	size;
	public:
		Span(void);
		Span(unsigned int n);
		Span(const Span& rhs);
		~Span(void);
		Span& operator=(const Span& rhs);
		void addNumber(int n) throw (AddFail);
		void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) throw (AddFail);
		int shortestSpan(void) throw (ShortFail);
		int longestSpan(void) throw (LongFail);
		std::vector<int> getNumber(void);
};

#endif