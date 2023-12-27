/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:57:05 by abrisse           #+#    #+#             */
/*   Updated: 2023/12/27 13:41:07 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

class Awesome
{
	public:
	
		Awesome(void): _n(42) {return;}
		int	get(void) const {return this->_n;}

	private:
	
		int _n;
};

std::ostream &	operator<<(std::ostream & o, Awesome const & rhs) { o << rhs.get(); return o; }

template<typename T>
void print(T & x) {std::cout << x << std::endl; return;}


void	square(int &i)
{
	i *= i;
}

int	main( void )
{
	{
		std::cout << "-------------------------------------------" << std::endl;

		int			intArray[5]		= {1, 2, 3, 4, 5};
		std::string	stringArray[2]	= {"42", "quarante-deux"};

		::iter(intArray, 5, ::printData);

		::iter(intArray, 5, square);
		std::cout << std::endl << "square function..." << std::endl;

		::iter(intArray, 5, ::printData);

		std::cout << std::endl;
		::iter(stringArray, 2, ::printData);
	}

	{
		std::cout << "-------------------------------------------" << std::endl;

		int	tab[] = {0,1,2,3,4};
		
		Awesome tab2[5];

		iter(tab, 5, print);
		iter(tab2, 5, print);
	}

	return 0;
}