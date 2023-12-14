/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:08:39 by abrisse           #+#    #+#             */
/*   Updated: 2023/11/03 20:41:39 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat( void );
		Bureaucrat( Bureaucrat const & );
		Bureaucrat &	operator=( Bureaucrat const & );
		~Bureaucrat( void );

		Bureaucrat( const std::string &name, int grade );

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
		int					getGrade( void ) const;

		void	incrementGrade( void );
		void	decrementGrade( void );

		void	signForm( AForm & form ) const;
		void	executeForm ( AForm const & form ) const;
};

std::ostream &	operator<<( std::ostream & o, Bureaucrat const & rhs );