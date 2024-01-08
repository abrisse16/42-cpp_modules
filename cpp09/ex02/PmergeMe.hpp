/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 05:08:15 by abrisse           #+#    #+#             */
/*   Updated: 2024/01/08 08:57:20 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <deque>
#include <string>

#ifdef DEBUG
#define MAX_SIZE_DISPLAY -1
#else
#define MAX_SIZE_DISPLAY 5
#endif

class PmergeMe
{
	public:

		~PmergeMe(void);
		PmergeMe(int ac, char **av);

		void	runVectorSort(void);
		// void	runDequeSort(void);

		void	displayElements(void) const;
		void	displayVectorSequence(void) const;

	private:

		PmergeMe(void);
		PmergeMe(PmergeMe const &);
		PmergeMe &	operator=(PmergeMe const &);

		std::vector<int>	_elements;
		std::vector<int>	_vectorSequence;
		std::deque<int>		_dequeSequence;

		typedef std::pair<int, int>	pairInt;

		typedef std::vector<int>::iterator		vecIntIter;
		typedef	std::vector<pairInt>::iterator	vecPairIter;

		size_t				_sequenceSize;
};

// std::ostream &	operator<<(std::ostream & o, PmergeMe const & rhs);
