/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:43:28 by abrisse           #+#    #+#             */
/*   Updated: 2023/12/18 17:56:06 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

enum e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	LITERAL,
	UNKNOWN
};

class ScalarConverter
{
	private:

		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &);
		~ScalarConverter(void);
		ScalarConverter & operator=(ScalarConverter const &);


	public:

		static void	convert(const std::string &in);
};