/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 22:34:31 by abrisse           #+#    #+#             */
/*   Updated: 2023/02/07 22:57:29 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat( void ) : Animal()
{
	std::cout << "Cat Default constructor called" << std::endl;
	_type = "Cat";
}

Cat::Cat( Cat const & src ) : Animal( src )
{
	std::cout << "Cat Copy constructor called" << std::endl;
	*this = src;
}

Cat &	Cat::operator=( Cat const & rhs )
{
	std::cout << "Cat Copy assignment operator called" << std::endl;
	if ( this != &rhs )
		this->_type = rhs._type;
	return *this;
}

Cat::~Cat( void )
{
	std::cout << "Cat Destructor called" << std::endl;
}

void	Cat::makeSound( void ) const
{
	std::cout << _type << ": Miaou!" << std::endl;
}