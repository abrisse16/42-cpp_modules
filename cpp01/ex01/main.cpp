/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:01:23 by abrisse           #+#    #+#             */
/*   Updated: 2023/08/28 11:01:51 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie	*horde = zombieHorde(3, "Michael");

	for (int i = 0; i < 3; i++)
		horde[i].announce();
	delete [] horde;
	return 0;
}