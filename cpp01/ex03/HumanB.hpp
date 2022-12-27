/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:08:14 by abrisse           #+#    #+#             */
/*   Updated: 2022/12/27 14:28:25 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB
{
	private :
		std::string	_name;
		Weapon*		_weapon;
	
	public :
		HumanB( std::string name );
		~HumanB( void );
		void	attack(void);
		void	setWeapon( Weapon& weapon );
		
};

#endif