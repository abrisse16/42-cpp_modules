/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:12:59 by abrisse           #+#    #+#             */
/*   Updated: 2023/12/14 11:06:46 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;

	public:
		RobotomyRequestForm( void );
		RobotomyRequestForm( RobotomyRequestForm const & );
		RobotomyRequestForm &	operator=( RobotomyRequestForm const & );
		~RobotomyRequestForm( void );

		RobotomyRequestForm( const std::string &target);

		void	execute( Bureaucrat const & executor ) const;
};