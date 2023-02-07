/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:37:00 by abrisse           #+#    #+#             */
/*   Updated: 2023/02/07 11:17:13 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int	main()
{
	FragTrap	ted("Theodore");
	
	std::cout << std::endl;
	std::cout << "Hit points: " << ted.getHitPoints() << std::endl;
	std::cout << "Energy points: " << ted.getEnergyPoints() << std::endl;
	std::cout << "Attack damage: " << ted.getAttackDamage() << std::endl << std::endl;

	ted.attack("Roy");

	std::cout << std::endl;
	std::cout << "Hit points: " << ted.getHitPoints() << std::endl;
	std::cout << "Energy points: " << ted.getEnergyPoints() << std::endl;
	std::cout << "Attack damage: " << ted.getAttackDamage() << std::endl << std::endl;

	ted.takeDamage(15);
	ted.beRepaired(5);

	std::cout << std::endl;
	std::cout << "Hit points: " << ted.getHitPoints() << std::endl;
	std::cout << "Energy points: " << ted.getEnergyPoints() << std::endl;
	std::cout << "Attack damage: " << ted.getAttackDamage() << std::endl << std::endl;

	ted.highFivesGuys();

	std::cout << std::endl;

	return 0;
}