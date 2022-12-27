/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:03:54 by abrisse           #+#    #+#             */
/*   Updated: 2022/12/27 14:20:56 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
	private :
		std::string	_type;

	public :
		Weapon( const std::string type );
		~Weapon( void );
		std::string	getType( void ) const;
		void		setType( const std::string type);
};

#endif