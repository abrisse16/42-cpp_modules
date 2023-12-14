/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:55:15 by abrisse           #+#    #+#             */
/*   Updated: 2023/12/14 11:19:36 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "PresidentialPardonForm.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define NEUTRAL "\033[0m"

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm("Presidential Pardon Form", 25, 5), _target("default")
{
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & src ) : AForm(src), _target(src._target)
{
}

PresidentialPardonForm &	PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
    if ( this != &rhs )
        this->_target = rhs._target;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
}

PresidentialPardonForm::PresidentialPardonForm( const std::string &target) : AForm("Presidential Pardon Form", 25, 5), _target(target)
{
}

void    PresidentialPardonForm::execute( Bureaucrat const & executor ) const
{
    if (!getSigned())
        throw   FormNotSignedException();
    if (executor.getGrade() > getExecGrade())
        throw   GradeTooLowException();

    std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}