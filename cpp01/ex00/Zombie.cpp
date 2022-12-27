/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:51:41 by abrisse           #+#    #+#             */
/*   Updated: 2022/12/27 15:00:23 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"

#ifndef DEBUG

Zombie::Zombie(std::string name) : _name(name)
{
}

#else

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << "Zombie Constructor called: " << _name << std::endl;
}

#endif

Zombie::~Zombie()
{
	std::cout << "Zombie Destructor called: " << _name << std::endl;
}

void	Zombie::announce ( void )
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}