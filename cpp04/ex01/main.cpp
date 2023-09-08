#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int	main()
{
	{
		const Animal*	j = new Dog();
		const Animal*	i = new Cat();

		std::cout << std::endl;
		delete	j;
		delete	i;
	}
	std::cout << std::endl << std::endl;
	{
		Animal	*animals[10];
	
		for ( int i = 0; i < 10 ; i++ )
		{
			std::cout << "i = " << i + 1 << std::endl;
			if ( i % 2 == 0 )
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
		}
		
		std::cout << std::endl;

		for ( int i = 0; i < 10 ; i++ )
		{
			std::cout << "i = " << i + 1 << std::endl;
			std::cout << animals[i]->getType() << std::endl;
			delete animals[i];
		}			
	}
	std::cout << std::endl << std::endl;
	{
		const Dog	*dog = new Dog();
		const Cat	*cat = new Cat();
		const Animal	*j = new Dog(*dog);
		const Animal	*i = new Cat(*cat);

		std::cout << std::endl;

		delete	j;
		delete	i;
		delete	dog;
		delete	cat;
	}
	std::cout << std::endl << std::endl;
	{
		Dog basic;
		Dog tmp = basic;
	}
	return 0;
}
