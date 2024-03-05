/**======================
*            42sp
* @file      : Dog.hpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 22/02/2024
*========================**/

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal{
	private:
		Brain* _brain;
	public:
		Dog(void);
		Dog(const Dog& rhs);
		~Dog(void);
		Dog& operator=(const Dog& rhs);
		void makeSound(void)const;
		Brain* getBrain(void) const;
};

#endif