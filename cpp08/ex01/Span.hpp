/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 00:16:42 by abrisse           #+#    #+#             */
/*   Updated: 2024/01/02 00:50:21 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <algorithm>

class Span
{
	private:
		
		unsigned int		_N;
		std::vector<int>	_vector;


	public:

		Span( void );
		Span( Span const & );
		Span &	operator=( Span const & );
		~Span( void );

		Span( unsigned int N );

		class	FullException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};

		class	EmptyException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};


		void	addNumber( int number );
		int		shortestSpan( void );
		int		longestSpan( void );

		void	fillSpan( std::vector<int>::iterator begin, std::vector<int>::iterator end );
		void	randSpan( void );
};
