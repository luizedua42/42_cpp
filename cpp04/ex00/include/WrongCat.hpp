/**======================
*            42sp
* @file      : WrongCat.hpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 29/02/2024
*========================**/

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		WrongCat(void);
		WrongCat(const WrongCat& rhs);
		~WrongCat(void);
		WrongCat& operator=(const WrongCat& rhs);
		void makeSound(void) const;
};

#endif