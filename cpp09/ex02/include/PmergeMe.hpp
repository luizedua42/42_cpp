/**======================
*            42sp
* @file      : PmergeMe.hpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 19/03/2024
*========================**/

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>

class PmergeMe {
	private:

	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe& rhs);
		~PmergeMe(void);
		PmergeMe& operator=(const PmergeMe& rhs);
};

# endif