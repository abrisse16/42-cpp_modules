/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 22:24:07 by abrisse           #+#    #+#             */
/*   Updated: 2023/09/02 12:20:08 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
	private:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
	public:
		ClapTrap( void );
		ClapTrap( std::string name );
		ClapTrap( ClapTrap const & );
		ClapTrap &	operator=( ClapTrap const & );
		~ClapTrap( void );
		
		void	attack( const std::string& target );
		void	takeDamage( unsigned int amount );
		void	beRepaired( unsigned int amount );

		unsigned int	getHitPoints( void ) const;
		unsigned int	getEnergyPoints( void ) const;
		unsigned int	getAttackDamage( void ) const;
};

#endif
