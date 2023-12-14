/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:10:30 by abrisse           #+#    #+#             */
/*   Updated: 2023/12/14 11:57:56 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define NEUTRAL "\033[0m"

int main()
{
	srand(time(NULL));

	Intern	someRandomIntern;
	AForm*	rrf;
	AForm*	scf;
	AForm*	ppf;
	
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	scf = someRandomIntern.makeForm("shrubbery creation", "Garden");
	ppf = someRandomIntern.makeForm("presidential pardon", "Roberto");

	std::cout << *rrf << std::endl;
	std::cout << *scf << std::endl;
	std::cout << *ppf << std::endl;

	delete rrf;
	delete scf;
	delete ppf;

	AForm*	other = someRandomIntern.makeForm("machin request", "Bender");

	return 0;
}