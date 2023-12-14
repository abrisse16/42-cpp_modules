/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:20:48 by abrisse           #+#    #+#             */
/*   Updated: 2023/11/03 20:58:02 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>

#include "ShrubberyCreationForm.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define NEUTRAL "\033[0m"

// ShrubberyCreationForm( void );
// ShrubberyCreationForm( ShrubberyCreationForm const & );
// ShrubberyCreationForm &	operator=( ShrubberyCreationForm const & );
// ~ShrubberyCreationForm( void );

// ShrubberyCreationForm( const std::string &name, const std::string &target);

const std::string ShrubberyCreationForm::_tree(	"		  .     .  .      +     .      .          .\n"
												"     .       .      .     #       .           .\n"
												"        .      .         ###            .      .      .\n"
												"      .      .   \"#:. .:##\"##:. .:#\"  .      .\n"
												"          .      . \"####\"###\"####\"  .\n"
												"       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       .\n"
												"  .             \"#########\"#########\"        .        .\n"
												"        .    \"#:.  \"####\"###\"####\"  .:#\"   .       .\n"
												"     .     .  \"#######\"\"##\"##\"\"#######\"                  .\n"
												"                .\"##\"#####\"#####\"##\"           .      .\n"
												"    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     .\n"
												"      .     \"#######\"##\"#####\"##\"#######\"      .     .\n"
												"    .    .     \"#####\"\"#######\"\"#####\"    .      .\n"
												"            .     \"      000      \"    .     .\n"
												"       .         .   .   000     .        .       .\n"
												".. .. ..................O000O........................ ...... ...");

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src ) : AForm(src), _target(src._target)
{
}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	if ( this != &rhs )
		this->_target = rhs._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string &name, const std::string &target) : AForm(name, 145, 137), _target(target)
{
}

void	ShrubberyCreationForm::execute( Bureaucrat const & executor ) const
{
	if(!getSigned())
		throw FormNotSignedException();
	if(executor.getGrade() > getExecGrade())
		throw GradeTooLowException();
	
	std::ofstream ofs((_target + "_shrubbery").c_str());
	if (ofs.fail())
		throw std::ofstream::failure("Error opening file");
	ofs << _tree << std::endl;
	ofs.close();
}