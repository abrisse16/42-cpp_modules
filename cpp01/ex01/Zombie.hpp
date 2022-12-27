/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:01:42 by abrisse           #+#    #+#             */
/*   Updated: 2022/12/27 15:01:45 by abrisse          ###   ########.fr       */
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
		Zombie();
		~Zombie(void);
		void	announce ( void );
		void	setName ( std::string name );
};

Zombie	*zombieHorde( int N, std::string name );

#endif