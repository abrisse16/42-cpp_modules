/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:15:02 by abrisse           #+#    #+#             */
/*   Updated: 2023/11/03 21:33:54 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern( void )
{
}

Intern::Intern( Intern const & src )
{
    (void)src;
}

Intern & Intern::operator=( Intern const & rhs )
{
    (void)rhs;
    return *this;
}

Intern::~Intern( void )
{
}

AForm * Intern::_makePresidentialPardonForm( std::string const & name, std::string const & target )
{
    return new PresidentialPardonForm( name, target );
}

AForm * Intern::_makeRobotomyRequestForm( std::string const & name, std::string const & target )
{
    return new RobotomyRequestForm( name, target );
}

AForm * Intern::_makeShrubberyCreationForm( std::string const & name, std::string const & target )
{
    return new ShrubberyCreationForm( name, target );
}

