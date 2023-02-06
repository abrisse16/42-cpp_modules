/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:37:00 by abrisse           #+#    #+#             */
/*   Updated: 2023/02/06 01:16:26 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int	main()
{
	Fixed		a;
	Fixed const	b( Fixed(5.05f) * Fixed(2) );
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}

/* 
int	main()
{
	Fixed	a;
	Fixed	b( Fixed(5.05f) * Fixed(2) );

	std::cout << "a : " << a << std::endl;
	std::cout << "b : " << b << std::endl;
	std::cout << "raw a : " << a.getRawBits() << std::endl;
	std::cout << "raw b : " << b.getRawBits() << std::endl;
	std::cout << "a + b : " << (a + b) << std::endl;
	std::cout << "a - b : " << (a - b) << std::endl;
	std::cout << "a * b : " << (a * b) << std::endl;
	std::cout << "a / b : " << (a / b) << std::endl;
	std::cout << "a > b : " << (a > b) << std::endl;
	std::cout << "a < b : " << (a < b) << std::endl;
	std::cout << "a >= b : " << (a >= b) << std::endl;
	std::cout << "a <= b : " << (a <= b) << std::endl;
	std::cout << "a == b : " << (a == b) << std::endl;
	std::cout << "a != b : " << (a != b) << std::endl;
	std::cout << "++a : " << ++a << std::endl;
	std::cout << "a : " << a << std::endl;
	std::cout << "a++ : " << a++ << std::endl;
	std::cout << "a : " << a << std::endl;
	std::cout << "--a : " << --a << std::endl;
	std::cout << "a : " << a << std::endl;
	std::cout << "a-- : " << a-- << std::endl;
	std::cout << "a : " << a << std::endl;
	std::cout << "min(a,b) : " << Fixed::min(a, b) << std::endl;
	std::cout << "max(a,b) : " << Fixed::max(a, b) << std::endl;


	a = Fixed(12);
	b = Fixed(5);
	
	std::cout << std::endl;
	std::cout << "a : " << a << std::endl;
	std::cout << "b : " << b << std::endl;
	std::cout << "raw a : " << a.getRawBits() << std::endl;
	std::cout << "raw b : " << b.getRawBits() << std::endl;
	std::cout << "a+b : " << (a + b) << std::endl;
	std::cout << "a-b : " << (a - b) << std::endl;
	std::cout << "a*b : " << (a * b) << std::endl;
	std::cout << "a/b : " << (a / b) << std::endl;
	std::cout << "a > b : " << (a > b) << std::endl;
	std::cout << "a < b : " << (a < b) << std::endl;
	std::cout << "a >= b : " << (a >= b) << std::endl;
	std::cout << "a <= b : " << (a <= b) << std::endl;
	std::cout << "a == b : " << (a == b) << std::endl;
	std::cout << "a != b : " << (a != b) << std::endl;
	std::cout << "++a : " << ++a << std::endl;
	std::cout << "a : " << a << std::endl;
	std::cout << "a++ : " << a++ << std::endl;
	std::cout << "a : " << a << std::endl;
	std::cout << "--a : " << --a << std::endl;
	std::cout << "a : " << a << std::endl;
	std::cout << "a-- : " << a-- << std::endl;
	std::cout << "a : " << a << std::endl;
	std::cout << "min(a,b) : " << Fixed::min(a, b) << std::endl;
	std::cout << "max(a,b) : " << Fixed::max(a, b) << std::endl;


	a = Fixed(42);
	b = Fixed(42);
	
	std::cout << std::endl;
	std::cout << "a : " << a << std::endl;
	std::cout << "b : " << b << std::endl;
	std::cout << "raw a : " << a.getRawBits() << std::endl;
	std::cout << "raw b : " << b.getRawBits() << std::endl;
	std::cout << "a+b : " << (a + b) << std::endl;
	std::cout << "a-b : " << (a - b) << std::endl;
	std::cout << "a*b : " << (a * b) << std::endl;
	std::cout << "a/b : " << (a / b) << std::endl;
	std::cout << "a > b : " << (a > b) << std::endl;
	std::cout << "a < b : " << (a < b) << std::endl;
	std::cout << "a >= b : " << (a >= b) << std::endl;
	std::cout << "a <= b : " << (a <= b) << std::endl;
	std::cout << "a == b : " << (a == b) << std::endl;
	std::cout << "a != b : " << (a != b) << std::endl;
	std::cout << "++a : " << ++a << std::endl;
	std::cout << "a : " << a << std::endl;
	std::cout << "a++ : " << a++ << std::endl;
	std::cout << "a : " << a << std::endl;
	std::cout << "--a : " << --a << std::endl;
	std::cout << "a : " << a << std::endl;
	std::cout << "a-- : " << a-- << std::endl;
	std::cout << "a : " << a << std::endl;
	std::cout << "min(a,b) : " << Fixed::min(a, b) << std::endl;
	std::cout << "max(a,b) : " << Fixed::max(a, b) << std::endl;


	return 0;
}
 */