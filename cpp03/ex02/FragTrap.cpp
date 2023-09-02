/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 23:19:03 by abrisse           #+#    #+#             */
/*   Updated: 2023/09/02 14:07:12 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap( "Default" )
{
	std::cout << "FragTrap Default constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	return;
}

FragTrap::FragTrap( std::string name ) : ClapTrap( name )
{
	std::cout << "FragTrap String constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	return;
}

FragTrap::FragTrap( FragTrap const & src ) : ClapTrap( src )
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = src;
	return;
}

FragTrap &	FragTrap::operator=( FragTrap const & rhs )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return *this;
}

FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap Destructor called" << std::endl;
	return;
}

void	FragTrap::attack( const std::string& target )
{
	std::cout << "FragTrap " << this->_name;
	if (this->_hitPoints == 0)
	{
		std::cout << " is dead!" << std::endl;
		return;
	}
	if (this->_energyPoints == 0)
		std::cout << " has no energy points" << std::endl;
	else
	{
		std::cout << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
}

void	FragTrap::highFivesGuys( void )
{
	std::cout << "FragTrap " << _name << " request a high five!" << std::endl;
}