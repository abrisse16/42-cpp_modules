/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 00:25:30 by abrisse           #+#    #+#             */
/*   Updated: 2024/01/02 01:01:25 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( void ) : _N(0) { }

Span::Span( Span const & src )
{
	_N = src._N;
	_vector.clear();
	_vector.insert(_vector.begin(), src._vector.begin(), src._vector.end());
}

Span &	Span::operator=( Span const & rhs )
{
	if ( this != &rhs )
	{
		_N = rhs._N;
		_vector.clear();
		_vector.insert(_vector.begin(), rhs._vector.begin(), rhs._vector.end());
	}
	return *this;
}

Span::~Span( void ) { }

Span::Span( unsigned int N ) : _N(N) { }


const char *Span::FullException::what() const throw()
{
	return "Span is full";
}

const char *Span::EmptyException::what() const throw()
{
	return "Span is empty or contains only one element";
}

void	Span::addNumber( int number )
{
	if (_vector.size() >= _N)
		throw Span::FullException();
	_vector.push_back(number);
}

int		Span::shortestSpan( void )
{
	if (_vector.size() <= 1)
		throw Span::EmptyException();
	std::vector<int>	tmp(_vector);
	std::sort(tmp.begin(), tmp.end());
	int	min = tmp[1] - tmp[0];
	for (unsigned int i = 1; i < tmp.size(); i++)
	{
		if (tmp[i] - tmp[i - 1] < min)
			min = tmp[i] - tmp[i - 1];
	}
	return min;
}

int		Span::longestSpan( void )
{
	if (_vector.size() <= 1)
		throw Span::EmptyException();
	std::vector<int>	tmp(_vector);
	std::sort(tmp.begin(), tmp.end());
	return tmp[tmp.size() - 1] - tmp[0];
}

void	Span::fillSpan( std::vector<int>::iterator begin, std::vector<int>::iterator end )
{
	for (std::vector<int>::iterator it = begin; it != end; it++)
	{
		if (_vector.size() >= _N)
			throw Span::FullException();
		_vector.push_back(*it);
	}
}

void	Span::randSpan( void )
{
	for (unsigned int i = 0; i < _N; i++)
		_vector.push_back(rand() % 100000);
}