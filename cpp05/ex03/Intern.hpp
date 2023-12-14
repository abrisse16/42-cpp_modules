/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:10:10 by abrisse           #+#    #+#             */
/*   Updated: 2023/11/03 21:14:48 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    private:
        static AForm * _makePresidentialPardonForm( std::string const & name, std::string const & target );
        static AForm * _makeRobotomyRequestForm( std::string const & name, std::string const & target );
        static AForm * _makeShrubberyCreationForm( std::string const & name, std::string const & target );
    public:
        Intern( void );
        Intern( Intern const & );
        Intern & operator=( Intern const & );
        ~Intern( void );

        AForm * makeForm( std::string const & name, std::string const & target );
}