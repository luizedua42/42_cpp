/**======================
*            42sp
* @file      : utils.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 17/03/2024
*========================**/

#include <iostream>

void remove_whitespaces(std::string& str) {
	size_t pos = str.find_first_not_of(" \t");

	str.erase(0, pos);
	pos = str.find_last_not_of(" \t");
	if (std::string::npos != pos)
		str.erase(pos + 1);
}

void remove_spaces(std::string& str) {
	std::string newStr = "";
	for (std::string::iterator it = str.begin(); it != str.end(); it++) {
		if (*it != ' ')
			newStr += *it;
	}
	str = newStr;
}