/**======================
*            42sp
* @file      : main.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 22/02/2024
*========================**/

#include "../include/AAnimal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/Brain.hpp"

namespace tests{
	void singleAnimal(void){
		std::cout << YELLOW << "Single Animal test======================" << RESET << std::endl;
		const AAnimal* dog = new Dog();
		const AAnimal* cat = new Cat();
		
		dog->makeSound();
		cat->makeSound();
		dog->getBrain()->setIdea(0, "Serve Humanity");
		cat->getBrain()->setIdea(0, "Slave Humanity");
		std::cout << dog->getBrain()->getIdea(0) << std::endl;
		std::cout << cat->getBrain()->getIdea(0) << std::endl;
		delete dog;//should not create a leak
		delete cat;
	}
	void packsnClowder(){
	
		std::cout << YELLOW << "Packs & Clowder test======================" << RESET << std::endl;
		int zoo = 10;
		std::string const thought[2] = {"I'm a dog", "I'm a cat"};
		const AAnimal* animals[zoo];
		while (zoo--)
		{
			if (zoo % 2)
				animals[zoo] = new Dog();
			else
				animals[zoo] = new Cat();
			animals[zoo]->getBrain()->setIdea(0, thought[zoo % 2]);
		}
		zoo = 10;
		while (zoo--)
			std::cout << animals[zoo]->getBrain()->getIdea(0) << std::endl;
		while (++zoo < 10)
			delete animals[zoo];
	
	}
	void deepCopy(){
		std::cout << YELLOW << "Deep copy test======================" << RESET << std::endl;
		Dog* dog = new Dog();
		Cat* cat = new Cat();
		for(int i = 0; i < 100; i++){
			dog->getBrain()->setIdea(i, "Serve Humanity");
			cat->getBrain()->setIdea(i, "Slave Humanity");
		}
		Cat* copyCat = new Cat(*cat);
		Dog* copyDog = new Dog(*dog);
		std::cout << std::endl;
		std::cout << "cat addres:" << cat << std::endl;
		std::cout << "copycat addres:" << copyCat << std::endl;
		std::cout << "dog addres:" << dog << std::endl;
		std::cout << "copydog addres:" << copyDog << std::endl;
		std::cout << std::endl;
		for(int i = 0; i < 100; i++){
			std::cout << "copydog: " << copyDog->getBrain()->getIdea(i) << std::endl;
			std::cout << "copycat: " << copyCat->getBrain()->getIdea(i) << std::endl;
		}
		delete dog;
		delete cat;
		delete copyDog;
		delete copyCat;
	}
}

int main(void){
	tests::singleAnimal();
	std::cout << std::endl;
	tests::packsnClowder();
	std::cout << std::endl;
	tests::deepCopy();
	return 0;
}
