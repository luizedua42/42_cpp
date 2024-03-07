/**======================
*            42sp
* @file      : AForm.hpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 06/03/2024
*========================**/

#pragma once
#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>
# include "Bureaucrat.hpp"

	
class Bureaucrat;

class AForm {
	private:
		const std::string _name;
		const int _gradeToSign;
		const int _gradeToExecute;
		bool _signed;
	public:
		// Exceptions ============================================================
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class NotSignedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		// =======================================================================
		AForm(void);
		AForm(std::string const name, int gradeToSign, int gradeToExecute)
			throw(GradeTooHighException, GradeTooLowException);
		AForm(const AForm& rhs);
		~AForm(void);
		AForm& operator=(const AForm& rhs);
		// Getters ===============================================================
		void beSigned(const Bureaucrat& rhs)
		throw(GradeTooLowException);
		const std::string getName(void) const;
		bool getSigned(void) const;
		int getGradeToSign(void) const;
		int getGradeToExecute(void) const;
		virtual void execute(Bureaucrat const & executor) const
		throw(GradeTooLowException, NotSignedException) = 0;

};

std::ostream& operator<<(std::ostream& os, const AForm& rhs);

#endif