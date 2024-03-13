/**======================
*            42sp
* @file      : Data.hpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 12/03/2024
*========================**/

#ifndef DATA_HPP
# define DATA_HPP
# include "Colors.hpp"
# include <stdint.h>

class Data {
	private:
		uint32_t _data;
	public:
		Data(void);
		Data(const Data& rhs);
		~Data(void);
		Data& operator=(const Data& rhs);
		uint32_t getData(void) const;
		void setData(uint32_t data);
};

#endif