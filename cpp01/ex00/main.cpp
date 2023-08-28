/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:37:00 by abrisse           #+#    #+#             */
/*   Updated: 2023/08/28 10:56:07 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie	theodore = Zombie("Theodore");
	Zombie*	roy = newZombie("Roy");

	randomChump("Michael");
	
	theodore.announce();
	roy->announce();

	delete roy;
	return 0;
}