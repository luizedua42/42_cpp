/**======================
 * ?        ABOUT
 * @file      : HumanB.hpp
 * @author    : luizedua
 * @createdOn : 05/02/2024
 *========================**/

#ifndef HUMANB_HPP
# define  HUMANB_HPP
# include "Weapon.hpp"

class HumanB {
	private:
		std::string _name;
		Weapon* _weapon;
	public:
		HumanB(std::string name);
		~HumanB();
		std::string getName(void);
		void setName(std::string name);
		void setWeapon(Weapon& weapon);
		void attack();
};

#endif