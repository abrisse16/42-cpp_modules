/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:30:34 by abrisse           #+#    #+#             */
/*   Updated: 2023/11/03 20:58:08 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

#include "RobotomyRequestForm.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define NEUTRAL "\033[0m"

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src ) : AForm(src), _target(src._target)
{
}

RobotomyRequestForm &	RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
    if ( this != &rhs )
        this->_target = rhs._target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
}

RobotomyRequestForm::RobotomyRequestForm( const std::string &name, const std::string &target) : AForm(name, 72, 45), _target(target)
{
}

void    RobotomyRequestForm::execute( Bureaucrat const & executor ) const
{
    if (!getSigned())
        throw   FormNotSignedException();
    if (executor.getGrade() > getExecGrade())
        throw   GradeTooLowException();
    std::cout << "* drilling noises *" << std::endl;
    if (rand() % 2)
        std::cout << _target << " has been robotomized successfully" << std::endl;
    else
        std::cout << _target << " robotomization failed" << std::endl;
}