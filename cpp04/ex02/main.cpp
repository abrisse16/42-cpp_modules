#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int	main()
{
	//const Animal*	a = new Animal();
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();

	j->makeSound();
	i->makeSound();

	delete	j;
	delete	i;

	return 0;
}