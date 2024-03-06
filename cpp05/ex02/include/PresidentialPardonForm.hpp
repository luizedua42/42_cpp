/**======================
*            42sp
* @file      : PresidentialPardonForm.hpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 06/03/2024
*========================**/

#pragma once
#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		const std::string _target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string const target);
		PresidentialPardonForm(const PresidentialPardonForm& rhs);
		~PresidentialPardonForm(void);

		PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);

		void execute(Bureaucrat const & executor) const
			throw(GradeTooLowException, NotSignedException);
};

#endif
