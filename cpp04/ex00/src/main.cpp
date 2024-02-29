/**======================
*            42sp
* @file      : main.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 22/02/2024
*========================**/

#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongCat.hpp"
#include "../include/WrongAnimal.hpp"

void wrongTest(void) {
	std::cout << MAGENTA << "wrong tests" << std::endl;
	const WrongAnimal* meta = new WrongAnimal();
	const Animal* j = new Dog();
	const WrongAnimal* i = new WrongCat();	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
}

int main(){
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound(); //will output the dog sound!
	meta->makeSound();
	
	delete i;
	delete j;
	delete meta;
	wrongTest();
	
	return 0;

}