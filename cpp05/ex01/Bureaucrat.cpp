/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:18:53 by abrisse           #+#    #+#             */
/*   Updated: 2023/11/03 17:10:00 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat( void ) : _name("Jim"), _grade(75)
{
}

Bureaucrat::Bureaucrat( Bureaucrat const & src ) : _name(src._name), _grade(src._grade)
{
}

Bureaucrat &	Bureaucrat::operator=( Bureaucrat const & rhs )
{
	if ( this != &rhs )
		this->_grade = rhs._grade;
	return *this;
}

Bureaucrat::~Bureaucrat( void )
{
}

Bureaucrat::Bureaucrat( const std::string &name, int grade ) : _name(name), _grade(grade)
{
	if ( grade < 1 )
		throw Bureaucrat::GradeTooHighException();
	if ( grade > 150 )
		throw Bureaucrat::GradeTooLowException();
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const	std::string & Bureaucrat::getName( void ) const
{
	return this->_name;
}

int	Bureaucrat::getGrade( void ) const
{
	return this->_grade;
}

void	Bureaucrat::incrementGrade( void )
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::decrementGrade( void )
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

std::ostream &	operator<<( std::ostream & o, Bureaucrat const & rhs )
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return o;
}

void	Bureaucrat::signForm( Form & form ) const
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch (Form::GradeTooLowException & e)
	{
		std::cout << this->_name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
	}
}