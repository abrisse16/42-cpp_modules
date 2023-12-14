/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:06:34 by abrisse           #+#    #+#             */
/*   Updated: 2023/10/24 12:06:36 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define RED "\033[31m"
#define NEUTRAL "\033[0m"

int	main()
{
	try
	{
		Bureaucrat	ted("Ted", 2);

		std::cout << ted << std::endl;
		ted.incrementGrade();
		std::cout << ted << std::endl;
		ted.incrementGrade();
		std::cout << ted << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << NEUTRAL << std::endl;
	}
	try
	{
		Bureaucrat	roy("Roy", 149);

		std::cout << roy << std::endl;
		roy.decrementGrade();
		std::cout << roy << std::endl;
		roy.decrementGrade();
		std::cout << roy << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << RED << e.what() << NEUTRAL << std::endl;
	}
	
	return 0;
}