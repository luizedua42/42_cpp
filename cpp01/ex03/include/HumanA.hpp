/**======================
 * ?        ABOUT
 * @file      : HumanA.hpp
 * @author    : luizedua
 * @createdOn : 05/02/2024
 *========================**/

#ifndef HUMANA_HPP
# define  HUMANA_HPP
# include "Weapon.hpp"

class HumanA {
	private:
		std::string _name;
		Weapon* _weapon;
	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA();
		std::string getName(void);
		void setName(std::string name);
		void setWeapon(Weapon& weapon);
		void attack();
};

#endif