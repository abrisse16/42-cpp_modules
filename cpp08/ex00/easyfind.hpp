/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 00:06:04 by abrisse           #+#    #+#             */
/*   Updated: 2024/01/02 00:15:26 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <algorithm>

template<typename T>
typename T::iterator	easyfind(T &container, int const to_find)
{
	typename T::iterator	it = find(container.begin(), container.end(), to_find);
	if (it != container.end())
		return (it);
	throw std::invalid_argument("Value not found");
}