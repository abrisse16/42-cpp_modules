/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:37:00 by abrisse           #+#    #+#             */
/*   Updated: 2022/12/27 14:37:01 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie	theodore = Zombie("Theodore");
	Zombie*	roy = newZombie("Roy");

	randomChump("Collin");
	
	theodore.announce();
	roy->announce();

	delete roy;
	return 0;
}