/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:52:55 by abrisse           #+#    #+#             */
/*   Updated: 2023/12/14 11:18:14 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#include "AForm.hpp"

class   PresidentialPardonForm : public AForm
{
    private:
        std::string _target;

    public:
        PresidentialPardonForm( void );
        PresidentialPardonForm( PresidentialPardonForm const & );
        PresidentialPardonForm &    operator=( PresidentialPardonForm const & );
        ~PresidentialPardonForm( void );

        PresidentialPardonForm( const std::string &target);

        void    execute( Bureaucrat const & executor ) const;
};