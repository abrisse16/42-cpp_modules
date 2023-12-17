/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:31:43 by abrisse           #+#    #+#             */
/*   Updated: 2023/12/17 16:02:33 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) : _in("")
{
}

ScalarConverter::ScalarConverter(ScalarConverter const & src) : _in(src._in)
{
}

ScalarConverter::~ScalarConverter(void)
{
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & rhs)
{
	if (this != &rhs)
		_in = rhs._in;
	return *this;
}

ScalarConverter::ScalarConverter(const std::string &in) : _in(in)
{
	if (_in.empty())
		throw std::invalid_argument("empty string");
	if (_isChar())
	{
		_type = CHAR;
		_longValue = static_cast<long>(_in[0]);
	}
	else if (_isInt())
	{
		_type = INT;
		_longValue = std::strtol(_in.c_str(), NULL, 10);
		if (_longValue > INT_MAX || _longValue < INT_MIN)
			throw std::invalid_argument("int overflow");
	}
	else if (_isFloat())
	{
		_type = FLOAT;
		float	floatValue = std::strtof(_in.c_str(), NULL);

		// _longValue = static_cast<long>(floatValue);			// ne fonctionne pas car on perd la précision
		_longValue = reinterpret_cast<long&>(floatValue);		// reinterpret_cast permet de convertir un float en long sans perdre la précision
	}
	else if (_isDouble())
	{
		_type = DOUBLE;
		double	doubleValue = std::strtod(_in.c_str(), NULL);
		_longValue = reinterpret_cast<long&>(doubleValue);
	}
	else if (_isLiteral())
	{
		_type = LITERAL;
	}
	else
		throw std::invalid_argument("invalid argument");
}

void	ScalarConverter::convert(void) const
{
	switch (_type)
	{
		case CHAR:
			_convertFromChar();
			break;
		case INT:
			_convertFromInt();
			break;
		case FLOAT:
			_convertFromFloat();
			break;
		case DOUBLE:
			_convertFromDouble();
			break;
		case LITERAL:
			_convertFromLiteral();
			break;
	}
}

bool	ScalarConverter::_isChar(void) const
{
		if (_in.length() == 1 && !isdigit(_in[0]))
			return true;
		return false;
}

bool	ScalarConverter::_isInt(void) const
{
	for (size_t i = 0; i < _in.length(); i++)
	{
		if (!isdigit(_in[i]) && !(i == 0 && (_in[i] == '-' || _in[i] == '+')))
			return false;
	}
	return true;
}

bool	ScalarConverter::_isDouble(void) const
{
	size_t i;

	for (i = 0; i < _in.length(); i++)
	{
		if (!isdigit(_in[i]) && !(i == 0 && (_in[i] == '-' || _in[i] == '+')) && _in[i] != '.')
			return false;
		if (_in[i] == '.')
			break;
	}
	if (i == _in.length() - 1)
		return false;
	for (i = i + 1; i < _in.length(); i++)
	{
		if (!isdigit(_in[i]))
			return false;
	}
	return true;
}

bool	ScalarConverter::_isFloat(void) const
{
	size_t i;

	for (i = 0; i < _in.length(); i++)
	{
		if (!isdigit(_in[i]) && !(i == 0 && (_in[i] == '-' || _in[i] == '+')) && _in[i] != '.')
			return false;
		if (_in[i] == '.')
			break;
	}
	if (i == _in.length() - 1)
		return false;
	for (i = i + 1; i < _in.length() - 1; i++)
	{
		if (!isdigit(_in[i]))
			return false;
	}
	if (_in[i] != 'f')
		return false;
	return true;
}

bool	ScalarConverter::_isLiteral(void) const
{
	std::string oth[6] = {"nan", "nanf", "-inf", "+inf", "-inff", "+inff"};
	for (int i = 0; i < 6; i++)
		if (_in == oth[i])
			return true;
	return false;
}

void	ScalarConverter::_convertFromChar(void) const
{
	char c = static_cast<char>(_longValue);
	std::stringstream ssChar;
	std::stringstream ssInt;
	std::stringstream ssFloat;
	std::stringstream ssDouble;

	if (std::isprint(c))
		ssChar << "'" << c << "'";
	else
		ssChar << "non displayable";
	ssInt << static_cast<int>(_longValue);
	ssFloat << static_cast<float>(_longValue) << ".0f";
	ssDouble << static_cast<double>(_longValue) << ".0";

	_display(ssChar, ssInt, ssFloat, ssDouble);
}

void	ScalarConverter::_convertFromInt(void) const
{
	int	i = static_cast<int>(_longValue);
	std::stringstream ssChar;
	std::stringstream ssInt;
	std::stringstream ssFloat;
	std::stringstream ssDouble;

	if (std::isprint(i))
		ssChar << "'" << static_cast<char>(i) << "'";
	else if (isascii(i))
		ssChar << "non displayable";
	else
		ssChar << "impossible";
	ssInt << i;
	ssFloat << static_cast<float>(_longValue) << ".0f";
	ssDouble << static_cast<double>(_longValue) << ".0";

	_display(ssChar, ssInt, ssFloat, ssDouble);
}

void	ScalarConverter::_convertFromFloat(void) const
{
	float	f = *reinterpret_cast<const float*>(&_longValue);
	std::stringstream ssChar;
	std::stringstream ssInt;
	std::stringstream ssFloat;
	std::stringstream ssDouble;

	if (std::isprint(f))
		ssChar << "'" << static_cast<char>(f) << "'";
	else if (isascii(f))
		ssChar << "non displayable";
	else
		ssChar << "impossible";
	ssInt << static_cast<int>(f);
	ssFloat << f << "f";
	ssDouble << static_cast<double>(f);

	_display(ssChar, ssInt, ssFloat, ssDouble);
}

void	ScalarConverter::_convertFromDouble(void) const
{
	double	d = *reinterpret_cast<const double*>(&_longValue);
	std::stringstream ssChar;
	std::stringstream ssInt;
	std::stringstream ssFloat;
	std::stringstream ssDouble;

	if (std::isprint(d))
		ssChar << "'" << static_cast<char>(d) << "'";
	else if (isascii(d))
		ssChar << "non displayable";
	else
		ssChar << "impossible";
	ssInt << static_cast<int>(d);
	ssFloat << static_cast<float>(d) << "f";
	ssDouble << d;

	_display(ssChar, ssInt, ssFloat, ssDouble);
}

void	ScalarConverter::_convertFromLiteral(void) const
{
	std::stringstream ssChar;
	std::stringstream ssInt;
	std::stringstream ssFloat;
	std::stringstream ssDouble;

	ssChar << "impossible";
	ssInt << "impossible";
	if (_in == "-inff" || _in == "-inf")
	{
		ssFloat << "-inff";
		ssDouble << "-inf";
	}
	else if (_in == "+inff" || _in == "+inf")
	{
		ssFloat << "+inff";
		ssDouble << "+inf";
	}
	else
	{
		ssFloat << "nanf";
		ssDouble << "nan";
	}

	_display(ssChar, ssInt, ssFloat, ssDouble);
}

void	ScalarConverter::_display(std::stringstream &ssChar, std::stringstream &ssInt, std::stringstream &ssFloat, std::stringstream &ssDouble) const
{
	std::cout << std::setw(8) << "char: " << ssChar.str() << std::endl;
	std::cout << std::setw(8) << "int: " << ssInt.str() << std::endl;
	std::cout << std::setw(8) << "float: " << ssFloat.str() << std::endl;
	std::cout << std::setw(8) << "double: " << ssDouble.str() << std::endl;
}