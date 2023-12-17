/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:19:17 by abrisse           #+#    #+#             */
/*   Updated: 2023/12/17 15:55:31 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <sstream>

enum e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	LITERAL
};

class ScalarConverter
{
	public:

		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &);
		~ScalarConverter(void);
		ScalarConverter & operator=(ScalarConverter const &);
	
		ScalarConverter(const std::string &in);

		void	convert(void) const;


	private:

		std::string		_in;
		e_type			_type;
		long			_longValue;

		bool	_isChar(void) const;
		bool	_isInt(void) const;
		bool	_isFloat(void) const;
		bool	_isDouble(void) const;
		bool	_isLiteral(void) const;

		void	_convertFromChar(void) const;
		void	_convertFromInt(void) const;
		void	_convertFromFloat(void) const;
		void	_convertFromDouble(void) const;
		void	_convertFromLiteral(void) const;

		void	_display(std::stringstream &ssChar, std::stringstream &ssInt, std::stringstream &ssFloat, std::stringstream &ssDouble) const;
};