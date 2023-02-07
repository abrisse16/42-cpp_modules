/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:37:00 by abrisse           #+#    #+#             */
/*   Updated: 2023/02/07 01:16:03 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int	main()
{
	ClapTrap	ted("Theodore");
	
	std::cout << std::endl;
	std::cout << "Hit points: " << ted.getHitPoints() << std::endl;
	std::cout << "Energy points: " << ted.getEnergyPoints() << std::endl;
	std::cout << "Attack damage: " << ted.getAttackDamage() << std::endl << std::endl;

	ted.attack("Roy");

	std::cout << std::endl;

	ClapTrap	roy(ted);
	ted = ClapTrap("Roger");
	
	std::cout << std::endl;
	std::cout << "Hit points: " << roy.getHitPoints() << std::endl;
	std::cout << "Energy points: " << roy.getEnergyPoints() << std::endl;
	std::cout << "Attack damage: " << roy.getAttackDamage() << std::endl << std::endl;

	std::cout << std::endl;
	std::cout << "Hit points: " << ted.getHitPoints() << std::endl;
	std::cout << "Energy points: " << ted.getEnergyPoints() << std::endl;
	std::cout << "Attack damage: " << ted.getAttackDamage() << std::endl << std::endl;

	std::cout << "Hit points: " << ted.getHitPoints() << std::endl;
	std::cout << "Energy damage: " << ted.getEnergyPoints() << std::endl << std::endl;

	for (int i = 0; i < 3; i++)
	{
		ted.takeDamage(7);
		ted.beRepaired(5);
		std::cout << "Hit points: " << ted.getHitPoints() << std::endl;
		std::cout << "Energy damage: " << ted.getEnergyPoints() << std::endl << std::endl;
	}

	ted.attack("Roy");

	return 0;
}