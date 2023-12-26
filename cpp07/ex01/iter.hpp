/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:49:10 by abrisse           #+#    #+#             */
/*   Updated: 2023/12/26 17:54:31 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template<typename T>
void	iter( T const * array, size_t len, void func(T const &)){
	size_t	i = 0;
	while (i < len)
	{
		func(array[i]);
		i++;
	}
}

template<typename T>
void	printData(T const & data)
{
	std::cout << data << std::endl;
}