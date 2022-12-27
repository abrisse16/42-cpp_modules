/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:06:05 by abrisse           #+#    #+#             */
/*   Updated: 2022/12/27 14:29:51 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "HumanA.hpp"

#ifndef DEBUG

HumanA::HumanA( std::string name, Weapon& weapon) : _name(name), _weapon(weapon)
{
}

HumanA::~HumanA()
{
}

#else

HumanA::HumanA( std::string name, Weapon& weapon) : _name(name), _weapon(weapon)
{
	std::cout << "HumanA Constructor called : " << name << " , " << weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "HumanA Destructor called : " << _name << " , " << _weapon.getType() << std::endl;
}

#endif

void	HumanA::attack(void)
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}