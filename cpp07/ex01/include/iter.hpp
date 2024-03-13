/**======================
*            42sp
* @file      : iter.hpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 13/03/2024
*========================**/

#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template< typename T >
void iter(T *array, size_t length, void (*f)(T const &)) {
	for (size_t i = 0; i < length; i++) {
		f(array[i]);
	}
}

template< typename T >
void iter(T const *array, size_t length, void (*f)(T const &)) {
	for (size_t i = 0; i < length; i++) {
		f(array[i]);
	}
}

#endif