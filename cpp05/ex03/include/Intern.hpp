/**======================
*            42sp
* @file      : Intern.hpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 07/03/2024
*========================**/
#pragma once
#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"

class Intern {
	public:
		Intern(void);
		Intern(const Intern& rhs);
		~Intern(void);
		Intern& operator=(const Intern& rhs);

		AForm* makeForm(std::string formName, std::string target) const;
		
};



#endif