/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:10:30 by abrisse           #+#    #+#             */
/*   Updated: 2023/11/03 20:56:08 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define NEUTRAL "\033[0m"

int main()
{
	srand(time(NULL));
	try
	{
		Bureaucrat	jim("Jim", 150);
		Bureaucrat	michael("Michael", 1);
		ShrubberyCreationForm	homeShrubbery("Home Shrubbery Form", "Home");
		RobotomyRequestForm		robotomyRequest("Robotomy Form", "Bender");
		PresidentialPardonForm	presidentialPardon("Pardon Form", "Ted");

		std::cout << jim << std::endl;
		std::cout << michael << std::endl;
		std::cout << homeShrubbery << std::endl;
		std::cout << robotomyRequest << std::endl;
		std::cout << presidentialPardon << std::endl;

		std::cout << std::endl;

		michael.executeForm(homeShrubbery);
		michael.executeForm(robotomyRequest);
		michael.executeForm(presidentialPardon);
		
		std::cout << std::endl;

		std::cout << homeShrubbery << std::endl;
		jim.signForm(homeShrubbery);
		std::cout << homeShrubbery << std::endl;
		michael.signForm(homeShrubbery);
		std::cout << homeShrubbery << std::endl;

		michael.signForm(robotomyRequest);
		std::cout << robotomyRequest << std::endl;
		michael.signForm(presidentialPardon);
		std::cout << presidentialPardon << std::endl;

		std::cout << std::endl;

		jim.executeForm(homeShrubbery);
		michael.executeForm(homeShrubbery);
		michael.executeForm(robotomyRequest);
		michael.executeForm(presidentialPardon);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}