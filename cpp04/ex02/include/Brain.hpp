/**======================
*            42sp
* @file      : Brain.hpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 04/03/2024
*========================**/

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>
# include "Colors.hpp"

class Brain {
	private:
		std::string _ideas[100];
	public:
		Brain(void);
		Brain(const Brain& rhs);
		~Brain(void);
		Brain& operator=(const Brain& rhs);
		void setIdea(unsigned int i, std::string Idea);
		std::string getIdea(unsigned int i) const;
};

#endif