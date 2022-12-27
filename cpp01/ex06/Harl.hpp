/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:24:43 by abrisse           #+#    #+#             */
/*   Updated: 2022/12/27 13:29:22 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class	Harl
{
	private :
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
		int		_level;
	
	public :
		Harl( std::string minLevel );
		~Harl( void );
		void	complain( std::string level );
		int		getLevel() const;
};

#endif