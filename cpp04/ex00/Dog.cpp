/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 22:34:31 by abrisse           #+#    #+#             */
/*   Updated: 2023/02/07 22:57:32 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog( void ) : Animal()
{
	std::cout << "Dog Default constructor called" << std::endl;
	_type = "Dog";
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
		this->_type = rhs._type;
	return *this;
}

Dog::~Dog( void )
{
	std::cout << "Dog Destructor called" << std::endl;
}

void	Dog::makeSound( void ) const
{
	std::cout << _type << ": Woof Woof!" << std::endl;
}