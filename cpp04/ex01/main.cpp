#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int	main()
{
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();

	delete	j;
	delete	i;

	std::cout << std::endl;

	Animal	*animals[10];
	
	for ( int i = 0; i < 10 ; i++ )
	{
		if ( i % 2 == 0 )
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	for ( int i = 0; i < 10 ; i++ )
		std::cout << animals[i]->getType() << std::endl;

	for ( int i = 0; i < 10 ; i++ )
		delete animals[i];


	return 0;
}
