/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:59:45 by abrisse           #+#    #+#             */
/*   Updated: 2023/02/06 01:27:47 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

# include "Fixed.hpp"

class	Point
{
	private :
		const Fixed	_x;
		const Fixed	_y;

	
	public :
		Point( void );
		Point( float const x, float const y);
		Point( Point const & src );
		~Point( void );
	
		Point &	operator=( Point const & rhs );
		Fixed	getX( void ) const;
		Fixed	getY( void ) const;

};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif