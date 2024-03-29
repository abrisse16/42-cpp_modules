/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:36:04 by abrisse           #+#    #+#             */
/*   Updated: 2023/12/18 17:35:43 by abrisse          ###   ########.fr       */
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

	return 0;
}