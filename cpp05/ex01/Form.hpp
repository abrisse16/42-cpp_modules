/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 23:12:57 by abrisse           #+#    #+#             */
/*   Updated: 2023/10/23 00:50:05 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;

	public:
		Form( void );
		Form( Form const & );
		Form &	operator=( Form const & );
		~Form( void );

		Form( const std::string &name, const int signGrade, const int execGrade );

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};

		const std::string &	getName( void ) const;
		bool				getSigned( void ) const;
		int					getSignGrade( void ) const;
		int					getExecGrade( void ) const;

		void	beSigned( Bureaucrat const & );
};

std::ostream &	operator<<( std::ostream & o, Form const & rhs );