#include "../include/ScalarConverter.hpp"
#include <sstream>
#include <cmath>

Types impossibleTypes(std::string const& str) {
	Types tarr[8] = {TNAN, TNAN, NINF, NINF, PINF, PINF, PINF, PINF};

	std::string types[8] = {"nan", "nanf", "-inf", "-inff", "+inf", "+inff", "inf", "inff"};
	for (int i = 0; i < 8; i++) {
		if (str == types[i]) {
			return tarr[i];
		}
	}
	return INVALID;
}

Types testOverflow(std::string const& str) {
	std::istringstream iss(str);
	int num = 0;
	iss.exceptions(std::ios::failbit);
	try {
		iss >> num;
	} catch (std::exception& e) {
		(void)e;
		return INVALID;
	}
	return INT;
}

Types testInfinite(std::string const& str, Types type) {
	std::istringstream iss(str);
	double numd = static_cast<double>(0);
	float numf = static_cast<float>(0);
	iss.exceptions(std::ios::failbit);
	switch(type)
	{	
		case FLOAT:
			try {
				iss >> numf;
				if(std::isinf(numf))
					return numf < 0 ? NINF : PINF;
				return FLOAT;
			} catch (std::exception& e) {
				(void)e;
				return INVALID;
			}
			break;
		case DOUBLE:
			try {
				iss >> numd;
				if(std::isinf(numd))
					return numd < 0 ? NINF : PINF;
				return DOUBLE;
			} catch (std::exception& e) {
				(void)e;
				return INVALID;
			}
			break;
		default:
			return INVALID;
	}
}

Types validTypes(std::string const& str) {
	if(str.size() == 1 && !isdigit(str[0]))
		return CHAR;
	else if(str.find_first_of(".") == std::string::npos)
		return testOverflow(str);
	else if(str.find_first_of("f") != std::string::npos)
		return testInfinite(str, FLOAT);
	else if(str.find_first_of(".") != std::string::npos)
		return testInfinite(str, DOUBLE);
	return INVALID;
}

Types detectType(std::string const& str) {
	switch (impossibleTypes(str)) {
		case TNAN:
			return TNAN;
		case NINF:
			return NINF;
		case PINF:
			return PINF;
		default:
			break;
	}
	switch (validTypes(str)) {
		case CHAR:
			return CHAR;
		case INT:
			return INT;
		case FLOAT:
			return FLOAT;
		case DOUBLE:
			return DOUBLE;
		case INVALID:
			return INVALID;
		case PINF:
			return PINF;
		case NINF:
			return NINF;
		default:
			break;
	}
	return INVALID;
}