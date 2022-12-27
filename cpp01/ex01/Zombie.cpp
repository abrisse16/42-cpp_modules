/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:01:37 by abrisse           #+#    #+#             */
/*   Updated: 2022/12/27 15:02:48 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"

#ifndef DEBUG

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
}

#else

Zombie::Zombie()
{
	std::cout << "Zombie Constructor called" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie Destructor called: " << _name << std::endl;
}

#endif

void	Zombie::announce ( void )
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName ( std::string name )
{
	this->_name = name;
}