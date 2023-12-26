/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:57:05 by abrisse           #+#    #+#             */
/*   Updated: 2023/12/26 22:51:54 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

void	square(int &i)
{
	i *= i;
}

int	main( void )
{
	int			intArray[5]		= {1, 2, 3, 4, 5};
	std::string	stringArray[2]	= {"42", "quarante-deux"};

	::iter(intArray, 5, ::printData);

	::iter(intArray, 5, square);
	std::cout << std::endl << "square function..." << std::endl;

	::iter(intArray, 5, ::printData);

	std::cout << std::endl;
	::iter(stringArray, 2, ::printData);

}