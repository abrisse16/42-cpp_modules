/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:57:05 by abrisse           #+#    #+#             */
/*   Updated: 2023/12/26 17:54:22 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

int	main( void )
{
	int			intArray[3]		= {42, 21, 19};
	float		floatArray[3]	= {42.42, 21.21, 19.19};
	std::string	stringArray[2]	= {"42", "quarante-deux"};

	std::cout << "----- Int Array -----" << std::endl;
	::iter<int>(intArray, 3, ::printData);

	std::cout << std::endl;
	
	std::cout << "----- Float Array -----" << std::endl;
	::iter<float>(floatArray, 3, ::printData);

	std::cout << std::endl;
	
	std::cout << "----- String Array -----" << std::endl;
	::iter<std::string>(stringArray, 2, ::printData);
}