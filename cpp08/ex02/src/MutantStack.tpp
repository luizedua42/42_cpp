/**======================
*            42sp
* @file      : MutantStack.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 14/03/2024
*========================**/
#include "../includes/MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(void) : std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& rhs) : std::stack<T>(rhs) {
	*this = rhs;
}

template <typename T>
MutantStack<T>::~MutantStack(void) {}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& rhs) {
	if (this != &rhs) {
		std::stack<T>::operator=(rhs);
	}
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return this->c.end();
}