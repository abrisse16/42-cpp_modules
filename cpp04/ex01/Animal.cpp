/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 22:34:31 by abrisse           #+#    #+#             */
/*   Updated: 2023/09/07 16:19:00 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal( void )
{
	std::cout << "Animal Default constructor called" << std::endl;
	_type = "Animal";
}

Animal::Animal( Animal const & src )
{
	std::cout << "Animal Copy constructor called" << std::endl;
	*this = src;
}

Animal &	Animal::operator=( Animal const & rhs )
{
	std::cout << "Animal Copy assignment operator called" << std::endl;
	if ( this != &rhs )
		this->_type = rhs._type;
	return *this;
}

Animal::~Animal( void )
{
	std::cout << "Animal Destructor called" << std::endl;
}

void	Animal::makeSound( void ) const
{
	std::cout << _type << ": *weird sound*" << std::endl;
}

std::string	Animal::getType( void ) const
{
	return _type;
}