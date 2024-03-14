/**======================
*            42sp
* @file      : easyfind.hpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 14/03/2024
*========================**/

#ifndef EASYFIND_HPP
#define EASYFIND_HPP
# include <iostream>
# include <algorithm>

template <typename T>
int easyfind(T &container, int value) {
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end()) {
		throw std::exception();
	}
	return *it;
};

#endif