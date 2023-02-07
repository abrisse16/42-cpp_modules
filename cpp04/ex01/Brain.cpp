/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 23:38:45 by abrisse           #+#    #+#             */
/*   Updated: 2023/02/07 23:42:12 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Brain.hpp"

Brain::Brain( void )
{
	std::cout << "Brain Default constructor called" << std::endl;
}

Brain::Brain( Brain const & src )
{
	std::cout << "Brain Copy constructor called" << std::endl;
	*this = src;
	return;
}

Brain &	Brain::operator=( Brain const & rhs )
{
	std::cout << "Brain Copy assignment operator called" << std::endl;
	if ( this != &rhs )
		for ( int i = 0; i < 100; i++ )
			this->_ideas[i] = rhs._ideas[i];
	return *this;
}

Brain::~Brain( void )
{
	std::cout << "Brain Destructor called" << std::endl;
}