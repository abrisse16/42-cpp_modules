/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:05:38 by abrisse           #+#    #+#             */
/*   Updated: 2022/12/27 14:22:24 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA
{
	private :
		std::string	_name;
		Weapon&		_weapon;
	
	public :
		HumanA( std::string name, Weapon& weapon );
		~HumanA( void );
		void	attack(void);
		
};

#endif