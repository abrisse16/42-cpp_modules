/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 23:19:03 by abrisse           #+#    #+#             */
/*   Updated: 2023/09/06 20:36:33 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap( "Default" )
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	return;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap( name )
{
	std::cout << "ScavTrap String constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	return;
}

ScavTrap::ScavTrap( ScavTrap const & src ) : ClapTrap( src )
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = src;
	return;
}

ScavTrap &	ScavTrap::operator=( ScavTrap const & rhs )
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

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap Destructor called" << std::endl;
	return;
}

void	ScavTrap::attack( const std::string& target )
{
	std::cout << "ScavTrap " << this->_name;
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

void	ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap " << _name << " is in Gate Keeper mode" << std::endl;
}