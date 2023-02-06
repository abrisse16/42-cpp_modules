/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:24:21 by abrisse           #+#    #+#             */
/*   Updated: 2023/02/05 23:29:52 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed( void ) : _rawBits ( 0 )
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed( int const n ) : _rawBits ( n << _fractionalBitNb )
{
	std::cout << "Int constructor called" << std::endl;
	return;
}

Fixed::Fixed( float const z ) : _rawBits ( roundf(z * (1 << _fractionalBitNb)) )
{
	std::cout << "Float constructor called" << std::endl;
	return;
}

Fixed::Fixed ( Fixed const & src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
	return;
}

int	Fixed::getRawBits( void ) const
{
//	std::cout << "getRawBits member function called" << std::endl;
	return this->_rawBits;
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_rawBits = raw;
}

Fixed &	Fixed::operator=( Fixed const & rhs )
{
	std::cout << "Copy assignment operator called" << std::endl;
	
	if ( this != &rhs )
		this->_rawBits = rhs.getRawBits();
	
	return *this;
}

float	Fixed::toFloat( void ) const
{
	return ((float)_rawBits / (1 << _fractionalBitNb));
}

int		Fixed::toInt( void ) const
{
	return _rawBits / (1 << _fractionalBitNb);
}

std::ostream &	operator<<( std::ostream & o, Fixed const & rhs )
{
	o << rhs.toFloat();
	return o;
}