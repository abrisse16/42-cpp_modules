/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:59:45 by abrisse           #+#    #+#             */
/*   Updated: 2023/02/05 20:19:53 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class	Fixed
{
	private :
		int					_rawBits;
		static const int	_fractionBitNb = 8;
	
	public :
		Fixed( void );
		Fixed( Fixed const & src );
		~Fixed( void );

		Fixed &	operator=( Fixed const & rhs );
		
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif