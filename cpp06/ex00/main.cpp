/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:36:04 by abrisse           #+#    #+#             */
/*   Updated: 2023/12/17 19:33:17 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include <limits.h>
#include <float.h>

#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac != 2) {
		std::cout << "usage: ./convert [string]" << std::endl;
		return 0;
	}
	try {
		ScalarConverter::convert(av[1]);
	}
	catch (std::exception &e) {
		std::cout << "error: " << e.what() << std::endl;
	}

	// std::cout << std::endl << std::endl;
	// std::cout << "INT_MIN: " << INT_MIN << std::endl;
	// std::cout << "INT_MAX: " << INT_MAX << std::endl;
	// std::cout << "FLT_MIN: " << FLT_MIN << std::endl;
	// std::cout << "FLT_MAX: " << FLT_MAX << std::endl;
	// std::cout << "DBL_MIN: " << DBL_MIN << std::endl;
	// std::cout << "DBL_MAX: " << DBL_MAX << std::endl;

	return 0;
}