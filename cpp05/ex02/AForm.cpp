/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 23:42:20 by abrisse           #+#    #+#             */
/*   Updated: 2023/10/24 18:42:40 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/*
 *	const std::string	_name;
 *	bool				_signed;
 *	const int			_signGrade;
 *	const int			_execGrade;
 */

AForm::AForm( void ) : _name("Form"), _signed(false), _signGrade(150), _execGrade(150)
{
}

AForm::AForm( AForm const & src ) : _name(src._name), _signed(src._signed), _signGrade(src._signGrade), _execGrade(src._execGrade)
{
}

AForm &	AForm::operator=( AForm const & rhs )
{
	if ( this != &rhs )
		this->_signed = rhs._signed;
	return *this;
}

AForm::~AForm( void )
{
}

AForm::AForm( const std::string &name, const int signGrade, const int execGrade ) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if ( signGrade < 1 || execGrade < 1 )
		throw AForm::GradeTooHighException();
	if ( signGrade > 150 || execGrade > 150 )
		throw AForm::GradeTooLowException();
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char	*AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed";
}

const std::string & AForm::getName( void ) const
{
	return this->_name;
}

bool	AForm::getSigned( void ) const
{
	return this->_signed;
}

int	AForm::getSignGrade( void ) const
{
	return this->_signGrade;
}

int	AForm::getExecGrade( void ) const
{
	return this->_execGrade;
}

void	AForm::beSigned( Bureaucrat const & b )
{
	if ( b.getGrade() > this->_signGrade )
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

std::ostream &	operator<<( std::ostream & o, AForm const & rhs )
{
	std::string signedStr = (rhs.getSigned()) ? "signed" : "not signed";
	o << rhs.getName() << " is " << signedStr << " (sign grade: " << rhs.getSignGrade() << ", exec grade: " << rhs.getExecGrade() << ")";
	return o;
}