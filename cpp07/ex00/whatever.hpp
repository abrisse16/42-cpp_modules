/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:27:48 by abrisse           #+#    #+#             */
/*   Updated: 2023/12/26 16:43:15 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template<typename T>
void	swap( T & x, T & y ) {
	T  tmp = x;

	x = y;
	y = tmp;
}

template<typename T>
T	min( T const & x, T const & y ) {
	return ( (x<y) ? x : y );
}

template<typename T>
T	max( T const & x, T const & y ) {
	return ( (x>y) ? x : y );
}