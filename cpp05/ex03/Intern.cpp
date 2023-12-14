/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:15:02 by abrisse           #+#    #+#             */
/*   Updated: 2023/12/14 11:47:56 by abrisse          ###   ########.fr       */
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

AForm * Intern::_makePresidentialPardonForm( std::string const & target )
{
    return new PresidentialPardonForm( target );
}

AForm * Intern::_makeRobotomyRequestForm( std::string const & target )
{
    return new RobotomyRequestForm( target );
}

AForm * Intern::_makeShrubberyCreationForm( std::string const & target )
{
    return new ShrubberyCreationForm( target );
}

AForm * Intern::makeForm( std::string const & name, std::string const & target )
{
    std::string const   names[3] = {
        "presidential pardon",
        "robotomy request",
        "shrubbery creation"
    };
    AForm * (*funcs[3])(std::string const &) = {
        Intern::_makePresidentialPardonForm,
        Intern::_makeRobotomyRequestForm,
        Intern::_makeShrubberyCreationForm
    };

    for (int i = 0; i < 3; i++)
    {
        if (name == names[i])
        {
            std::cout << "Intern creates " << name << std::endl;
            return funcs[i](target);
        }
    }
    std::cerr << "Intern doesn't know how to create " << name << std::endl;
    return NULL;
}
