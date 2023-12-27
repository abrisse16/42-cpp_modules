/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 23:10:08 by abrisse           #+#    #+#             */
/*   Updated: 2023/12/27 12:22:39 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

#include "Array.hpp"

#define MAX_VAL 10

int	main(void)
{
	{
		std::cout << "-------------------------------------------" << std::endl;

		Array<int>	numbers(MAX_VAL);
		int *		mirror = new int[MAX_VAL];
		
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int	value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}

		{
			Array<int>	tmp = numbers;
			Array<int>	test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}

		try
		{
			numbers[-2] = 0;
		}
		catch (const std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch (const std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}

		delete [] mirror;
	}

	{
		std::cout << "-------------------------------------------" << std::endl;

		Array<int>	numbers(MAX_VAL);

		for (int i = 0; i < MAX_VAL; i++)
		{
			std::cout << i << ": " << numbers[i] << std::endl;
		}

		std::cout << "-------------------------------------------" << std::endl;

		for (int i = 0; i < MAX_VAL; i++)
		{
			const int	value = rand();
			numbers[i] = value;
		}

		Array<int>	numbersCopy(numbers);
		for (int i = 0; i < MAX_VAL / 2; i++)
		{
			const int	value = rand();
			numbersCopy[i] = value;
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			std::cout << i << ": " << numbers[i] << "\t" << numbersCopy[i];
			if (numbers[i] != numbersCopy[i])
				std::cout << "\t<--" << std::endl;
			else
				std::cout << std::endl;
		}
	}

	return 0;
}