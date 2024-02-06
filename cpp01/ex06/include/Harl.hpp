/**======================
*            42sp
* @file      : Harl.hpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 06/02/2024
*========================**/

#ifndef HARL_HPP
# define HARL_HPP
# include <iostream>
# include <cstdlib>
# include <ctime>

class Harl {
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);

	public:
		Harl(void);
		~Harl(void);

		void complain(std::string level);
};

#endif