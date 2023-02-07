/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:37:00 by abrisse           #+#    #+#             */
/*   Updated: 2023/02/07 01:21:44 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

int	main()
{
	ScavTrap	ted("Theodore");
	
	std::cout << std::endl;
	std::cout << "Hit points: " << ted.getHitPoints() << std::endl;
	std::cout << "Energy points: " << ted.getEnergyPoints() << std::endl;
	std::cout << "Attack damage: " << ted.getAttackDamage() << std::endl << std::endl;

	ted.attack("Roy");

	std::cout << std::endl;
	std::cout << "Hit points: " << ted.getHitPoints() << std::endl;
	std::cout << "Energy points: " << ted.getEnergyPoints() << std::endl;
	std::cout << "Attack damage: " << ted.getAttackDamage() << std::endl << std::endl;

	ScavTrap	roy(ted);
	ted = ScavTrap("Roger");

	std::cout << std::endl;
	std::cout << "Hit points: " << roy.getHitPoints() << std::endl;
	std::cout << "Energy points: " << roy.getEnergyPoints() << std::endl;
	std::cout << "Attack damage: " << roy.getAttackDamage() << std::endl << std::endl;
	
	std::cout << std::endl;
	std::cout << "Hit points: " << ted.getHitPoints() << std::endl;
	std::cout << "Energy points: " << ted.getEnergyPoints() << std::endl;
	std::cout << "Attack damage: " << ted.getAttackDamage() << std::endl << std::endl;

	roy.attack("Someone");
	roy.takeDamage(15);
	roy.beRepaired(5);

	std::cout << std::endl;
	std::cout << "Hit points: " << roy.getHitPoints() << std::endl;
	std::cout << "Energy points: " << roy.getEnergyPoints() << std::endl;
	std::cout << "Attack damage: " << roy.getAttackDamage() << std::endl << std::endl;

	ted.guardGate();

	std::cout << std::endl;

	return 0;
}