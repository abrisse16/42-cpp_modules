/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 05:07:34 by abrisse           #+#    #+#             */
/*   Updated: 2024/01/08 06:43:02 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "PmergeMe.hpp"

double	launchTimer(PmergeMe & merge, void (PmergeMe::*func)(void))
{
	struct timespec	start, end;

	clock_gettime(CLOCK_MONOTONIC, &start);
	(merge.*func)();
	clock_gettime(CLOCK_MONOTONIC, &end);

	// double	duration = static_cast<double>(end.tv_sec - start.tv_sec);
	double	startNano = static_cast<double>(start.tv_nsec) * 1e-6;
	double	endNano = static_cast<double>(end.tv_nsec) * 1e-6;
	startNano += static_cast<double>(start.tv_sec) * 1e3;
	endNano += static_cast<double>(end.tv_sec) * 1e3;
	return (endNano - startNano);
}

// double	launchTimer(PmergeMe & merge, void (PmergeMe::*func)(void))
// {
// 	clock_t	start = clock();
// 	(merge.*func)();
// 	clock_t	end = clock();
// 	double	duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;

// 	std::cout << "After:\t";
// 	merge.displayElements();
// 	std::cout << std::endl;
// 	std::cout << "Duration: " << duration << "s" << std::endl;
// 	return duration;
// }

int	main(int ac, char **av)
{
	if (ac <= 1)
		return 0;

	try {
		PmergeMe	merge(ac - 1, av + 1);
		
		std::cout << "Before:\t";
		merge.displayElements();
		std::cout << std::endl;

		double	durationVector = launchTimer(merge, &PmergeMe::runVectorSort);

		std::cout << "Duration: " << durationVector << "ms" << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}