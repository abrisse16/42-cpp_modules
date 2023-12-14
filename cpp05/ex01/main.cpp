/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:06:28 by abrisse           #+#    #+#             */
/*   Updated: 2023/10/24 18:12:22 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

#define RED "\033[31m"
#define NEUTRAL "\033[0m"

int	main()
{
	try
	{
		Form	bidule("bidule", 0, 0);

		std::cout << bidule << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << NEUTRAL << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Form	machin("machin", 42, 42);
		std::cout << machin << std::endl;

		Form	bidule("bidule", 0, 0);
		std::cout << bidule << std::endl;

		Form	truc("truc", 151, 1);
		std::cout << truc << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << RED << "GradeTooLowException: " << e.what() << NEUTRAL << std::endl;
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << RED << "GradeTooHighException: " << e.what() << NEUTRAL << std::endl;
	}

	std::cout << std::endl;
	
	try
	{
		Form	le_formulaire("le_formulaire", 21, 42);
		Bureaucrat	jim("Jim", 100);
		Bureaucrat	michael("Michael", 12);

		std::cout << le_formulaire << std::endl;
		std::cout << jim << std::endl;
		std::cout << michael << std::endl;

		jim.signForm(le_formulaire);
		std::cout << le_formulaire << std::endl;
		michael.signForm(le_formulaire);
		std::cout << le_formulaire << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << NEUTRAL << std::endl;
	}

	return 0;
}