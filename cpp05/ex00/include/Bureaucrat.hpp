/**======================
*            42sp
* @file      : Bureaucrat.hpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 06/03/2024
*========================**/

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <cstdlib>
# include "Colors.hpp"



class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
};

class Bureaucrat {
	private:
		const std::string _name;
		int _grade;
	public:

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		Bureaucrat(void);
		Bureaucrat(std::string const name, int grade)
			throw(GradeTooHighException, GradeTooLowException);
		Bureaucrat(const Bureaucrat& rhs);
		~Bureaucrat(void);

		const std::string getName(void) const;
		void setName(std::string const name);
		int getGrade(void) const;
		void increaseGrade(void);
		void decreaseGrade(void);
		
		Bureaucrat& operator=(const Bureaucrat& rhs);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs);

#endif