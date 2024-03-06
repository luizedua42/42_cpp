/**======================
*            42sp
* @file      : Form.hpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 06/03/2024
*========================**/

#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include "Bureaucrat.hpp"

class Form {
	private:
		const std::string _name;
		const int _gradeToSign;
		const int _gradeToExecute;
		bool _signed;
	public:
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		
		Form(void);
		Form(std::string const name, int gradeToSign, int gradeToExecute)
			throw(GradeTooHighException, GradeTooLowException);
		Form(const Form& rhs);
		~Form(void);
		Form& operator=(const Form& rhs);

		void beSigned(const Bureaucrat& rhs);
		void signForm(void);
		const std::string getName(void) const;
		bool getSigned(void) const;
		int getGradeToSign(void) const;
		int getGradeToExecute(void) const;

};

std::ostream& operator<<(std::ostream& os, const Form& rhs);

#endif