/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:59:45 by abrisse           #+#    #+#             */
/*   Updated: 2023/02/05 23:21:00 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class	Fixed
{
	private :
		int					_rawBits;
		static const int	_fractionalBitNb = 8;
	
	public :
		Fixed( void );
		Fixed( Fixed const & src );
		~Fixed( void );
		Fixed( int const n );
		Fixed( float const z );

		Fixed &	operator=( Fixed const & rhs );
		
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs);

#endif