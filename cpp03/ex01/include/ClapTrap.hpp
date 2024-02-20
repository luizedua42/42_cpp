/**======================
*            42sp
* @file      : ClapTrap.hpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 19/02/2024
*========================**/

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>
# include "Colors.hpp"

class ClapTrap {
	protected:
		std::string _name;
		int _energyPoints;
		int _attackDamage;
		int _hitPoints; // Health
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& rhs);
		~ClapTrap(void);
		ClapTrap& operator=(const ClapTrap& rhs);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		std::string getName(void) const;
		int getEnergy(void) const;
		int getHit(void) const;
		int getAttack(void) const;
		void setName(std::string name);
		void setEnergy(int energy);
		void setHit(int hit);
		void setAttack(int attack);
};

#endif