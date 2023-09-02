/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 23:19:03 by abrisse           #+#    #+#             */
/*   Updated: 2023/09/02 12:21:11 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : _name( "Default" )
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
	return;
}

ClapTrap::ClapTrap( std::string name ) : _name ( name )
{
	std::cout << "ClapTrap String constructor called" << std::endl;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
	return;
}

ClapTrap::ClapTrap( ClapTrap const & src )
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	*this = src;
	return;
}

ClapTrap &	ClapTrap::operator=( ClapTrap const & rhs )
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

ClapTrap::~ClapTrap( void )
{
	std::cout << "ClapTrap Destructor called" << std::endl;
	return;
}

void	ClapTrap::attack( const std::string& target )
{
	std::cout << "ClapTrap " << this->_name;
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

void	ClapTrap::takeDamage( unsigned int amount )
{
	std::cout << "ClapTrap " << this->_name;
	if (this->_hitPoints == 0)
	{
		std::cout << " is already dead!" << std::endl;
		return;
	}
	std::cout << " took " << amount << " points of damage!" << std::endl;
	if (amount > this->_hitPoints)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	std::cout << "ClapTrap " << this->_name;
	if (this->_hitPoints == 0)
	{
		std::cout << " is dead!" << std::endl;
		return;
	}
	if (this->_energyPoints == 0)
		std::cout << " has no energy points" << std::endl;
	else
	{
		std::cout << " repairs " << amount << " hit points!" << std::endl;
		this->_energyPoints--;
		this->_hitPoints += amount;
	}
}

unsigned int	ClapTrap::getHitPoints( void ) const
{
	return _hitPoints;
}

unsigned int	ClapTrap::getEnergyPoints( void ) const
{
	return _energyPoints;
}

unsigned int	ClapTrap::getAttackDamage( void ) const
{
	return _attackDamage;
}
