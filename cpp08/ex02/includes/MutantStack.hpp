/**======================
*            42sp
* @file      : MutantStack.hpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 14/03/2024
*========================**/
#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <iostream>
# include <stack>
# include <vector>

template <typename T>
class MutantStack: public std::stack<T> {
	public:
		MutantStack(void);
		MutantStack(const MutantStack& rhs);
		~MutantStack(void);
		MutantStack& operator=(const MutantStack& rhs);
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin();
		iterator end();
};

# include "../src/MutantStack.tpp"

#endif