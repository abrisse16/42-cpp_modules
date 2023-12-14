/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 23:12:57 by abrisse           #+#    #+#             */
/*   Updated: 2023/10/27 21:53:42 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;

	public:
		AForm( void );
		AForm( AForm const & );
		AForm &	operator=( AForm const & );
		virtual ~AForm( void );

		AForm( const std::string &name, const int signGrade, const int execGrade );

		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};
		class	FormNotSignedException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};

		const std::string &	getName( void ) const;
		bool				getSigned( void ) const;
		int					getSignGrade( void ) const;
		int					getExecGrade( void ) const;

		void	beSigned( Bureaucrat const & );
		virtual void	execute( Bureaucrat const & executor ) const = 0;
};

std::ostream &	operator<<( std::ostream & o, AForm const & rhs );