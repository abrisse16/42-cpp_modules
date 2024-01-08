/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 03:00:11 by abrisse           #+#    #+#             */
/*   Updated: 2024/01/08 03:29:58 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "RPN.hpp"

int	main(int ac, char **av)
{
	RPN	rpn;

	for (int i = 1; i < ac; i++) {
		rpn.addInput(av[i]);
	}
	try {
		std::cout << rpn.calculate() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}