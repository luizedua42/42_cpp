/**======================
*            42sp
* @file      : Cat.hpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 22/02/2024
*========================**/

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal{
	public:
		Cat(void);
		Cat(const Cat& rhs);
		~Cat(void);
		Cat& operator=(const Cat& rhs);
		virtual void makeSound(void) const;
};

#endif