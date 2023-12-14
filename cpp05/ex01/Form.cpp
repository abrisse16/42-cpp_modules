/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 23:42:20 by abrisse           #+#    #+#             */
/*   Updated: 2023/10/23 00:43:13 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*
 *	const std::string	_name;
 *	bool				_signed;
 *	const int			_signGrade;
 *	const int			_execGrade;
 */

Form::Form( void ) : _name("Form"), _signed(false), _signGrade(150), _execGrade(150)
{
}

Form::Form( Form const & src ) : _name(src._name), _signed(src._signed), _signGrade(src._signGrade), _execGrade(src._execGrade)
{
}

Form &	Form::operator=( Form const & rhs )
{
	if ( this != &rhs )
		this->_signed = rhs._signed;
	return *this;
}

Form::~Form( void )
{
}

Form::Form( const std::string &name, const int signGrade, const int execGrade ) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if ( signGrade < 1 || execGrade < 1 )
		throw Form::GradeTooHighException();
	if ( signGrade > 150 || execGrade > 150 )
		throw Form::GradeTooLowException();
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const std::string & Form::getName( void ) const
{
	return this->_name;
}

bool	Form::getSigned( void ) const
{
	return this->_signed;
}

int	Form::getSignGrade( void ) const
{
	return this->_signGrade;
}

int	Form::getExecGrade( void ) const
{
	return this->_execGrade;
}

void	Form::beSigned( Bureaucrat const & b )
{
	if ( b.getGrade() > this->_signGrade )
		throw Form::GradeTooLowException();
	this->_signed = true;
}

std::ostream &	operator<<( std::ostream & o, Form const & rhs )
{
	std::string signedStr = (rhs.getSigned()) ? "signed" : "not signed";
	o << rhs.getName() << " is " << signedStr << " (sign grade: " << rhs.getSignGrade() << ", exec grade: " << rhs.getExecGrade() << ")";
	return o;
}