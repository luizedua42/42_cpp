/**======================
*            42sp
* @file      : ScalarConverter.hpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 07/03/2024
*========================**/

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# include "Colors.hpp"

enum Types {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PINF,
	NINF,
	TNAN,
	INVALID
};

class ScalarConverter {
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& rhs);
		~ScalarConverter(void);
		ScalarConverter& operator=(const ScalarConverter& rhs);
	public:
		static void converter(std::string const& str);

};

#endif