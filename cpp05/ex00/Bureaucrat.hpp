/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:08:39 by abrisse           #+#    #+#             */
/*   Updated: 2023/12/14 10:29:19 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

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
};

std::ostream &	operator<<( std::ostream & o, Bureaucrat const & rhs );

#endif