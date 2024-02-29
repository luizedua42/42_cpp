/**======================
*            42sp
* @file      : WrongAnimal.hpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 29/02/2024
*========================**/
#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>
# include "Colors.hpp"

class WrongAnimal {
	protected:
		std::string _type;
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal& rhs);
		~WrongAnimal(void);
		WrongAnimal& operator=(const WrongAnimal& rhs);
		void makeSound(void) const;
		std::string getType(void) const;
};

#endif