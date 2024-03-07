/**======================
*            42sp
* @file      : ShrubberyCreationForm.hpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 06/03/2024
*========================**/

#pragma once
#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		const std::string _target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const target);
		ShrubberyCreationForm(const ShrubberyCreationForm& rhs);
		~ShrubberyCreationForm(void);

		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);

		void execute(Bureaucrat const & executor) const
			throw(GradeTooLowException, NotSignedException);
};

#endif
