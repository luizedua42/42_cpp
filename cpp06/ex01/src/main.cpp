/**======================
*            42sp
* @file      : main.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 12/03/2024
*========================**/

#include "../include/Data.hpp"
#include "../include/Serializer.hpp"

int main()
{
	std::cout << YELLOW << "Serializer test ============================================"  << RESET << std::endl;

	Data* oldData = new Data();
	oldData->setData(42);
	uintptr_t rawData = Serializer::serialize(oldData);
	Data* newData = Serializer::deserialize(rawData);
	std::cout << "Old data: " << oldData->getData() << std::endl;
	std::cout << "New data: " << newData->getData() << std::endl;
	std::cout << "Raw Data: " << rawData << std::endl;


	std::cout << YELLOW << "Setting new data ============================================" << RESET << std::endl;
	
	oldData->setData(21);
	std::cout << "Old data: " << oldData->getData() << std::endl;
	std::cout << "New data: " << newData->getData() << std::endl;
	std::cout << "Raw Data: " << rawData << std::endl;
	delete oldData;
	return 0;
}
