/**======================
*            42sp
* @file      : Serializer.hpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 12/03/2024
*========================**/

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include "Colors.hpp"
# include "Data.hpp"
# include <stdint.h>

class Serializer {
	private:
		Serializer(void);
		Serializer(const Serializer& rhs);
		~Serializer(void);
		Serializer& operator=(const Serializer& rhs);
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif