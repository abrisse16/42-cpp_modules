/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 10:04:34 by abrisse           #+#    #+#             */
/*   Updated: 2023/12/17 14:48:48 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>

#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{

	if (ac != 2) {
		std::cout << "Usage: ./convert [string]" << std::endl;
		return 1;
	}
	try {
		ScalarConverter	sc(av[1]);
		sc.convert();
	}
	catch (std::exception &e) {
		std::cout << "error: " << e.what() << std::endl;
	}
	return 0;
}