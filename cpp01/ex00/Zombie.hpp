/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:51:38 by abrisse           #+#    #+#             */
/*   Updated: 2023/08/28 10:51:33 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
	private :
		std::string	_name;
	
	public :
		Zombie(std::string name);
		~Zombie(void);
		void	announce ( void );
};

Zombie*	newZombie( std::string name );

void	randomChump( std::string name );

#endif