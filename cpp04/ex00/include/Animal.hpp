/**======================
*            42sp
* @file      : Animal.hpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 22/02/2024
*========================**/

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
#include <iostream>
#include "Colors.hpp"

class Animal {
	protected:
		std::string _type;
	public:
		Animal(void);
		Animal(const Animal& rhs);
		virtual ~Animal(void);
		Animal& operator=(const Animal& rhs);
		virtual void makeSound(void) const;
		std::string getType() const;
		void setType(std::string type);
};

#endif