/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:12:59 by abrisse           #+#    #+#             */
/*   Updated: 2023/12/14 11:07:17 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string			_target;
		static const std::string	_tree;

	public:
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( ShrubberyCreationForm const & );
		ShrubberyCreationForm &	operator=( ShrubberyCreationForm const & );
		~ShrubberyCreationForm( void );

		ShrubberyCreationForm( const std::string &target);

		void	execute( Bureaucrat const & executor ) const;
};