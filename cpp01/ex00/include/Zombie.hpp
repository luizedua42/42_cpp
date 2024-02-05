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

void	randomChump(std::string name);
Zombie*	newZombie(std::string name);

#endif