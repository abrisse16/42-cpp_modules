/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 22:24:07 by abrisse           #+#    #+#             */
/*   Updated: 2023/02/07 11:09:20 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <string>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap( std::string );
		FragTrap( FragTrap const & );
		FragTrap &	operator=( FragTrap const & );
		~FragTrap( void );
		
		void	attack( const std::string& target );
		void	highFivesGuys( void );
};

#endif