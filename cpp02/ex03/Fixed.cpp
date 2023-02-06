/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:24:21 by abrisse           #+#    #+#             */
/*   Updated: 2023/02/06 01:14:00 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include <cmath>

#ifndef DEBUG

Fixed::Fixed( void ) : _rawBits ( 0 )
{
	return;
}

Fixed::Fixed( int const n ) : _rawBits ( n << _fractionalBitNb )
{
	return;
}

Fixed::Fixed( float const z ) : _rawBits ( roundf(z * (1 << _fractionalBitNb)) )
{
	return;
}

Fixed::Fixed ( Fixed const & src )
{
	*this = src;
	return;
}

Fixed::~Fixed( void )
{
	return;
}

int	Fixed::getRawBits( void ) const
{
	return this->_rawBits;
}

void	Fixed::setRawBits( int const raw )
{
	this->_rawBits = raw;
}

Fixed &	Fixed::operator=( Fixed const & rhs )
{
	if ( this != &rhs )
		this->_rawBits = rhs.getRawBits();
	
	return *this;
}

#else

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
	std::cout << "getRawBits member function called" << std::endl;
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

#endif



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

bool	Fixed::operator>( Fixed const & rhs ) const
{
	return (this->_rawBits > rhs.getRawBits());
}

bool	Fixed::operator<( Fixed const & rhs ) const
{
	return (this->_rawBits < rhs.getRawBits());
}

bool	Fixed::operator<=( Fixed const & rhs ) const
{
	return (this->_rawBits <= rhs.getRawBits());
}

bool	Fixed::operator>=( Fixed const & rhs ) const
{
	return (this->_rawBits >= rhs.getRawBits());
}

bool	Fixed::operator==( Fixed const & rhs ) const
{
	return (this->_rawBits == rhs.getRawBits());
}

bool	Fixed::operator!=( Fixed const & rhs ) const
{
	return (this->_rawBits != rhs.getRawBits());
}

Fixed	Fixed::operator+( Fixed const & rhs ) const
{
	return Fixed ( this->toFloat() + rhs.toFloat() );
}

Fixed	Fixed::operator-( Fixed const & rhs ) const
{
	return Fixed ( this->toFloat() - rhs.toFloat() );
}

Fixed	Fixed::operator*( Fixed const & rhs ) const
{
	return Fixed ( this->toFloat() * rhs.toFloat() );
}

Fixed	Fixed::operator/( Fixed const & rhs ) const
{
	return Fixed ( this->toFloat() / rhs.toFloat() );
}

Fixed&	Fixed::operator++( void )
{
	this->_rawBits++;
	return (*this);
}

Fixed	Fixed::operator++( int )
{
	Fixed	tmp(*this);
	this->_rawBits++;
	return (tmp);
}

Fixed&	Fixed::operator--( void )
{
	this->_rawBits--;
	return (*this);
}

Fixed	Fixed::operator--( int )
{
	Fixed	tmp(*this);
	this->_rawBits--;
	return (tmp);
}

Fixed&		Fixed::min(Fixed & lhs, Fixed & rhs)
{
	return (lhs < rhs ? lhs : rhs);
}

const Fixed&	Fixed::min(Fixed const & lhs, Fixed const & rhs)
{
	return (lhs < rhs ? lhs : rhs);
}

Fixed&		Fixed::max(Fixed & lhs, Fixed & rhs)
{
	return (lhs > rhs ? lhs : rhs);
}

const Fixed&	Fixed::max(Fixed const & lhs, Fixed const & rhs)
{
	return (lhs > rhs ? lhs : rhs);
}