/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 00:37:40 by abrisse           #+#    #+#             */
/*   Updated: 2024/01/02 01:01:57 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

#include "Span.hpp"

int main()
{
	srand(time(NULL));
	{
		std::cout << "-------------------------------------------" << std::endl;
		Span sp = Span(5);

		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		std::cout << "-------------------------------------------" << std::endl;
		Span sp = Span(1);
		sp.addNumber(42);

		try
		{
			std::cout << sp.shortestSpan() << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			sp.addNumber(21);
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "-------------------------------------------" << std::endl;
		std::vector<int> v;
		for (int i = 0; i < 100; i++)
			v.push_back(i);
		
		Span sp = Span(100);
		sp.fillSpan(v.begin(), v.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		std::cout << "-------------------------------------------" << std::endl;
		Span sp = Span(10000);
		for (int i = 0; i < 10000; i++)
			sp.addNumber(i);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	// {
	// 	std::cout << "-------------------------------------------" << std::endl;
	// 	Span sp = Span(1000);
	// 	sp.randSpan();
	// 	std::cout << sp.shortestSpan() << std::endl;
	// 	std::cout << sp.longestSpan() << std::endl;}
	
	return 0;
}