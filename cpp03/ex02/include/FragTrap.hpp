/**======================
*            42sp
* @file      : FragTrap.hpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 20/02/2024
*========================**/
#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap{
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap& rhs);
		~FragTrap(void);
		FragTrap& operator=(const FragTrap& rhs);
		void highFivesGuys(void);
};

#endif