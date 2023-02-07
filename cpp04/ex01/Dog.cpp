/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 22:34:31 by abrisse           #+#    #+#             */
/*   Updated: 2023/02/08 00:19:37 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog( void ) : Animal()
{
	std::cout << "Dog Default constructor called" << std::endl;
	_type = "Dog";
	_brain = new Brain();
}

Dog::Dog( Dog const & src ) : Animal( src )
{
	std::cout << "Dog Copy constructor called" << std::endl;
	*this = src;
}

Dog &	Dog::operator=( Dog const & rhs )
{
	std::cout << "Dog Copy assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		this->_type = rhs._type;
		*this->_brain = *rhs._brain;
	}
	return *this;
}

Dog::~Dog( void )
{
	delete _brain;
	std::cout << "Dog Destructor called" << std::endl;
}

void	Dog::makeSound( void ) const
{
	std::cout << _type << ": Woof Woof!" << std::endl;
}