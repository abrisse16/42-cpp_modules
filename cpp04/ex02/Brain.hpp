/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 23:36:57 by abrisse           #+#    #+#             */
/*   Updated: 2023/09/06 00:22:56 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
	private:
		std::string	_ideas[100];
	
	public:
		Brain( void );
		Brain( Brain const & src );
		Brain &	operator=( Brain const & rhs );
		~Brain( void );
};

#endif