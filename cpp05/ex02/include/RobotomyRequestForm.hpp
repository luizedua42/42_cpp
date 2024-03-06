/**======================
*            42sp
* @file      : RobotomyRequestForm.hpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 06/03/2024
*========================**/

#pragma once
#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
		const std::string _target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const target);
		RobotomyRequestForm(const RobotomyRequestForm& rhs);
		~RobotomyRequestForm(void);

		RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);

		void execute(Bureaucrat const & executor) const
			throw(GradeTooLowException, NotSignedException);
};

#endif
