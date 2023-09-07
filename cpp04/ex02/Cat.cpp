/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 22:34:31 by abrisse           #+#    #+#             */
/*   Updated: 2023/09/07 17:08:21 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat( void ) : Animal(), _brain ( new Brain() )
{
	std::cout << "Cat Default constructor called" << std::endl;
	_type = "Cat";
}

Cat::Cat( Cat const & src ) : Animal( src ), _brain ( new Brain() )
{
	std::cout << "Cat Copy constructor called" << std::endl;
	*this = src;
}

Cat &	Cat::operator=( Cat const & rhs )
{
	std::cout << "Cat Copy assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		this->_type = rhs._type;
		*this->_brain = *rhs._brain;
	}
	return *this;
}

Cat::~Cat( void )
{
	delete _brain;
	std::cout << "Cat Destructor called" << std::endl;
}

void	Cat::makeSound( void ) const
{
	std::cout << _type << ": Miaou!" << std::endl;
}