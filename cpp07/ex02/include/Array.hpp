/**======================
*            42sp
* @file      : Array.hpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 13/03/2024
*========================**/

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>

template< typename T >
class Array {
	private:
		T*		_array;
		unsigned int	_size;
	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array& rhs);
		~Array(void);
		Array& operator=(const Array& rhs);
		Array& operator[](unsigned int i) throw(std::out_of_range);
		unsigned int size(void) const;
};

#include "../src/Array.tpp"

#endif