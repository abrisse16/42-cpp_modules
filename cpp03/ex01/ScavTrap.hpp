/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 22:24:07 by abrisse           #+#    #+#             */
/*   Updated: 2023/09/02 13:27:44 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap( void );
		ScavTrap( std::string );
		ScavTrap( ScavTrap const & );
		ScavTrap &	operator=( ScavTrap const & );
		~ScavTrap( void );
		
		void	attack( const std::string& target );
		void	guardGate( void );
};

#endif
