/**======================
 * ?        ABOUT
 * @file      : Zombie.hpp
 * @author    : luizedua
 * @createdOn : 05/02/2024
 *========================**/

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {
	private:
		std::string	_name;
	public:
		Zombie(void);
		~Zombie(void);
		void		announce();
		std::string	getName(void);
		void		setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif