/**======================
*            42sp
* @file      : main.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 13/03/2024
*========================**/

#include "../include/Array.hpp"

int main(void) {
	//test array template with int, float and char types

	Array<int> intArray(5);
	Array<float> floatArray(5);
	Array<char> charArray(5);

	std::cout << "intArray size: " << intArray.size() << std::endl;
	std::cout << "floatArray size: " << floatArray.size() << std::endl;
	std::cout << "charArray size: " << charArray.size() << std::endl;
	std::cout << "copy tests ====================" << std::endl;

	Array<int> intArray2(intArray);
	Array<float> floatArray2(floatArray);
	Array<char> charArray2(charArray);

	std::cout << "intArray2 size: " << intArray2.size() << std::endl;
	std::cout << "floatArray2 size: " << floatArray2.size() << std::endl;
	std::cout << "charArray2 size: " << charArray2.size() << std::endl;

	return 0;
}