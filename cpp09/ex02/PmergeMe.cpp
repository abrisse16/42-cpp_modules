/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 05:42:37 by abrisse           #+#    #+#             */
/*   Updated: 2024/01/08 12:58:55 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <climits>
#include <algorithm>

std::ostream &	operator <<(std::ostream & o, std::pair<int, int> const & rhs)
{
	o << "(" << rhs.first << ", " << rhs.second << ")";
	return o;
}

PmergeMe::PmergeMe(void) { }

PmergeMe::PmergeMe(PmergeMe const & src) { *this = src; }

PmergeMe::~PmergeMe(void) { }

PmergeMe &	PmergeMe::operator=(PmergeMe const & rhs)
{
	if (this != &rhs)
	{
		this->_elements = rhs._elements;
		this->_vectorSequence = rhs._vectorSequence;
		this->_dequeSequence = rhs._dequeSequence;
	}
	return *this;
}

bool	isInt(std::string const & str)
{
	std::stringstream	ss(str);
	int					tmp;

	ss >> tmp;
	if (ss.fail() || !ss.eof())
		return false;
	return true;
}

PmergeMe::PmergeMe(int ac, char **av)
{
	for (int i = 0; i < ac; i++)
	{
		std::stringstream	ss(av[i]);
		std::string			token;

		while (ss >> token)
		{
			if (!isInt(token))
				throw std::invalid_argument("Error: invalid argument");
			long	longValue = std::strtol(token.c_str(), NULL, 10);
			if (longValue > INT_MAX || longValue <= 0)
				throw std::invalid_argument("Error: invalid argument");
			if (std::find(_elements.begin(), _elements.end(), static_cast<int>(longValue)) != _elements.end())
				throw std::invalid_argument("Error: repeated argument");
			_elements.push_back(static_cast<int>(longValue));
			_vectorSequence.push_back(static_cast<int>(longValue));
			_dequeSequence.push_back(static_cast<int>(longValue));
		}
	}
	_sequenceSize = _elements.size();
}

template<typename It>
void	display(It const & begin, It const & end)
{
	int	i = 0;
	It	it = begin;
	
	for (; it != end && i != MAX_SIZE_DISPLAY; it++, i++)
	{
		if (it != begin)
			std::cout << " ";
		std::cout << *it;
	}
	if (i == MAX_SIZE_DISPLAY && it != end)
		std::cout << " [...]";
}

void	PmergeMe::displayElements(void) const
{
	display(_elements.begin(), _elements.end());
}

void	PmergeMe::displayVectorSequence(void) const
{
	display(_vectorSequence.begin(), _vectorSequence.end());
}

size_t	PmergeMe::getSequenceSize(void) const
{
	return (this->_sequenceSize);
}

// void	insertGoodPosition(std::vector<int> & vec, std::vector<int>::iterator & it, int value)
// {
// 	for (; it != vec.end(); it++)
// 	{
// 		if (*it > value)
// 		{
// 			vec.insert(it, value);
// 			return ;
// 		}
// 	}
// 	vec.push_back(value);
// }


void	PmergeMe::runVectorSort(void)
{
	std::vector<pairInt>	pairs;
	vecIntIter				it = _vectorSequence.begin();
	int						lastValue = -1;
	
	// Step 1: create pairs arbitrarily
	if (_sequenceSize % 2 == 1)
	{
		lastValue = *it;
		it++;
	}
	for (; it != _vectorSequence.end(); it += 2)
	{
		pairInt	pair(*it, *(it + 1));

		// Step 2: sort pairs, to determine the larger of the two elements in each pair
		if (pair.first < pair.second)
			std::swap(pair.first, pair.second);
		pairs.push_back(pair);
	}
	_vectorSequence.clear();

	// Step 3: sort the larger elements of each pair, in ascending order
	std::sort(pairs.begin(), pairs.end());

	// Creating the sorted sequence of n/2 elements from step 3
	for (vecPairIter it = pairs.begin(); it != pairs.end(); it++)
		_vectorSequence.push_back(it->first);

	// Step 4
	vecIntIter	vectorIter = _vectorSequence.begin();
	_vectorSequence.insert(vectorIter, pairs.begin()->second);

	std::vector<int>	remainingElements;
	for (vecPairIter it = pairs.begin() + 1; it != pairs.end(); it++)
		remainingElements.push_back(it->second);
	if (lastValue != -1)
		remainingElements.push_back(lastValue);

	// Step 5
	// 5.1 Partition the uninserted elements
	std::vector<std::vector<int> >	groups;
	int	size = 2;
	int	previousSize = 0;
	int	power = 2;
	size_t	index = 0;

	while (index < remainingElements.size())
	{
		std::vector<int>	group;
		for (int i = 0; i < size && index < remainingElements.size(); ++i)
		{
			group.push_back(remainingElements[index]);
			++index;
		}
		groups.push_back(group);
		power *= 2;
		previousSize = size;

		while (size + previousSize < power)
			size++;
	}

	// // Display groups 
	// for (size_t i = 0; i < groups.size(); ++i)
	// {
	// 	std::cout << "Group " << i + 1 << ": ";
	// 	for (size_t j = 0; j < groups[i].size(); ++j)
	// 	{
	// 		std::cout << groups[i][j] << " ";
	// 	}
	// 	std::cout << std::endl;
	// }

	// 5.2 Order the uninserted elements by their groups (smaller indexes to
	// larger indexes), but within each group order them from larger indexes to
	// smaller indexes.
	for (size_t i = 0; i < groups.size(); ++i)
	{
		for (size_t j = groups[i].size(); j > 0; --j)
		{
			// std::cout << "Inserting " << groups[i][j - 1] << std::endl;
	 		std::vector<int>::iterator insertionPoint = std::upper_bound(_vectorSequence.begin(), _vectorSequence.end(), groups[i][j - 1]);
	 		_vectorSequence.insert(insertionPoint, groups[i][j - 1]);
		}
	}
}
