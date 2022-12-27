/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:08:25 by abrisse           #+#    #+#             */
/*   Updated: 2022/12/27 14:29:46 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "HumanB.hpp"

#ifndef DEBUG

HumanB::HumanB( std::string name ) : _name(name)
{
}

HumanB::~HumanB()
{
}

#else

HumanB::HumanB( std::string name ) : _name(name)
{
	std::cout << "HumanB Constructor called : " << name << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB Destructor called : " << _name << std::endl;
}

#endif

void	HumanB::attack(void)
{
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

void	HumanB::setWeapon( Weapon& weapon )
{
	_weapon = &weapon;
}