/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:44:07 by abrisse           #+#    #+#             */
/*   Updated: 2022/12/27 13:51:12 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "CopyAndReplace.hpp"

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "usage: " << av[0] << " filename oldString newString" << std::endl;
		return (0);
	}
	CopyAndReplace	copyAndReplace(av[1]);
	copyAndReplace.replace(av[2], av[3]);
	return 0;
}