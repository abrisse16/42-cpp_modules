/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 22:34:31 by abrisse           #+#    #+#             */
/*   Updated: 2023/02/07 23:14:24 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat( void ) : WrongAnimal()
{
	std::cout << "WrongCat Default constructor called" << std::endl;
	_type = "WrongCat";
}

WrongCat::WrongCat( WrongCat const & src ) : WrongAnimal( src )
{
	std::cout << "WrongCat Copy constructor called" << std::endl;
	*this = src;
}

WrongCat &	WrongCat::operator=( WrongCat const & rhs )
{
	std::cout << "WrongCat Copy assignment operator called" << std::endl;
	if ( this != &rhs )
		this->_type = rhs._type;
	return *this;
}

WrongCat::~WrongCat( void )
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

void	WrongCat::makeSound( void ) const
{
	std::cout << _type << ": Miaou!" << std::endl;
}