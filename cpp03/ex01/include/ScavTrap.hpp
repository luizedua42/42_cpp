/**======================
*            42sp
* @file      : ScavTrap.hpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 19/02/2024
*========================**/

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include <iostream>
# include "Colors.hpp"
# include "ClapTrap.hpp" 

class ScavTrap : public ClapTrap {
	
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& rhs);
		~ScavTrap(void);
		ScavTrap& operator=(const ScavTrap& rhs);
		void attack(const std::string& target);
		void guardGate();
};

#endif