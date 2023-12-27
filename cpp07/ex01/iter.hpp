/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:49:10 by abrisse           #+#    #+#             */
/*   Updated: 2023/12/27 13:40:47 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <iostream>

template<typename T>
void	iter( T * array, std::size_t len, void func(T &) ) {
	
	for (std::size_t i = 0; i < len; i++)
		func(array[i]);
}

template<typename T>
void	printData(T & data)
{
	std::cout << data << std::endl;
}