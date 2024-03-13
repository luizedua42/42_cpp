/**======================
*            42sp
* @file      : whatever.hpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 13/03/2024
*========================**/
#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template< typename T >
void swap(T &a, T &b) {
	T aux = a;
	a = b;
	b = aux;
}

template< typename T >
T min(T a, T b) {
	return (a < b) ? a : b;
}

template< typename T >
T max(T a, T b) {
	return (a > b) ? a : b;
}

#endif