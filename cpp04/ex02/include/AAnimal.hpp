/**======================
*            42sp
* @file      : AAnimal.hpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 22/02/2024
*========================**/

#ifndef A_ANIMAL_HPP
# define A_ANIMAL_HPP
# include <iostream>
# include "Colors.hpp"
# include "Brain.hpp"


class AAnimal {
	protected:
		std::string _type;
	public:
		AAnimal(void);
		AAnimal(const AAnimal& rhs);
		virtual ~AAnimal(void);
		AAnimal& operator=(const AAnimal& rhs);
		virtual void makeSound(void) const = 0;
		std::string getType() const;
		void setType(std::string type);
		virtual Brain* getBrain(void) const = 0;
};

#endif