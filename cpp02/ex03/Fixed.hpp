/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:59:45 by abrisse           #+#    #+#             */
/*   Updated: 2023/02/06 22:41:39 by abrisse          ###   ########.fr       */
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

		bool	operator>( Fixed const & rhs ) const;
		bool	operator<( Fixed const & rhs ) const;
		bool	operator>=( Fixed const & rhs ) const;
		bool	operator<=( Fixed const & rhs ) const;
		bool	operator==( Fixed const & rhs ) const;
		bool	operator!=( Fixed const & rhs ) const;

		Fixed	operator+( Fixed const & rhs ) const;
		Fixed	operator-( Fixed const & rhs ) const;
		Fixed	operator*( Fixed const & rhs ) const;
		Fixed	operator/( Fixed const & rhs ) const;

		Fixed&	operator++( void );
		Fixed	operator++( int );
		Fixed&	operator--( void );
		Fixed	operator--( int );
		
		static Fixed&		min(Fixed & lhs, Fixed & rhs);
		static const Fixed&	min(Fixed const & lhs, Fixed const & rhs);
		static Fixed&		max(Fixed & lhs, Fixed & rhs);
		static const Fixed&	max(Fixed const & lhs, Fixed const & rhs);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs);

#endif