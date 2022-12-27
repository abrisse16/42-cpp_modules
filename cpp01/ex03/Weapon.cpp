/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:03:58 by abrisse           #+#    #+#             */
/*   Updated: 2022/12/27 14:29:42 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Weapon.hpp"

#ifndef DEBUG

Weapon::Weapon( const std::string type ) : _type(type)
{
}

Weapon::~Weapon( void )
{
}

#else

Weapon::Weapon( const std::string type ) : _type(type)
{
	std::cout << "Weapon Constructor called : " << _type << std::endl;
}

Weapon::~Weapon( void )
{
	std::cout << "Weapon Destructor called : " << _type << std::endl;
}

#endif

std::string	Weapon::getType( void ) const
{
	return (_type);
}

void		Weapon::setType( const std::string type )
{
	_type = type;
}