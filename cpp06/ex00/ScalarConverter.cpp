/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:46:12 by abrisse           #+#    #+#             */
/*   Updated: 2023/12/18 12:25:50 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits.h>

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(ScalarConverter const & src)
{
    *this = src;
}

ScalarConverter::~ScalarConverter(void)
{
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & rhs)
{
    (void)rhs;
    return *this;
}

void    display(std::stringstream &ssChar, std::stringstream &ssInt, std::stringstream &ssFloat, std::stringstream &ssDouble)
{
    std::cout << std::setw(8) << "char: " << ssChar.str() << std::endl;
	std::cout << std::setw(8) << "int: " << ssInt.str() << std::endl;
	std::cout << std::setw(8) << "float: " << ssFloat.str() << std::endl;
	std::cout << std::setw(8) << "double: " << ssDouble.str() << std::endl;
}

bool	isChar(const std::string &in)
{
		if (in.length() == 1 && !isdigit(in[0]))
			return true;
		return false;
}

bool	isInt(const std::string &in)
{
	for (size_t i = 0; i < in.length(); i++)
	{
		if (!isdigit(in[i]) && !(i == 0 && (in[i] == '-' || in[i] == '+')))
			return false;
	}
	return true;
}

bool	isDouble(const std::string &in)
{
	size_t i;

	for (i = 0; i < in.length(); i++)
	{
		if (!isdigit(in[i]) && !(i == 0 && (in[i] == '-' || in[i] == '+')) && in[i] != '.')
			return false;
		if (in[i] == '.')
			break;
	}
	if (i == in.length() - 1)
		return false;
	for (i = i + 1; i < in.length(); i++)
	{
		if (!isdigit(in[i]))
			return false;
	}
	return true;
}

bool	isFloat(const std::string &in) 
{
	size_t i;

	for (i = 0; i < in.length(); i++)
	{
		if (!isdigit(in[i]) && !(i == 0 && (in[i] == '-' || in[i] == '+')) && in[i] != '.')
			return false;
		if (in[i] == '.')
			break;
	}
	if (i == in.length() - 1)
		return false;
	for (i = i + 1; i < in.length() - 1; i++)
	{
		if (!isdigit(in[i]))
			return false;
	}
	if (in[i] != 'f')
		return false;
	return true;
}

bool	isLiteral(const std::string &in)
{
	std::string litteral[6] = {"nan", "nanf", "-inf", "+inf", "-inff", "+inff"};
	for (int i = 0; i < 6; i++)
		if (in == litteral[i])
			return true;
	return false;
}

e_type  checkType(const std::string &in)
{
    if (isChar(in))
        return CHAR;
    if (isInt(in))
        return INT;
    if (isFloat(in))
        return FLOAT;
    if (isDouble(in))
        return DOUBLE;
    if (isLiteral(in))
        return LITERAL;
    return UNKNOWN;
}

void    convertFromChar(const std::string &in)
{
    std::stringstream   ssChar;
    std::stringstream   ssInt;
	std::stringstream   ssFloat;
	std::stringstream   ssDouble;

    if (std::isprint(in[0]))
        ssChar << "'" << in << "'";
    else
        ssChar << "non displayable";
    ssInt << static_cast<int>(in[0]);
    ssFloat << static_cast<float>(in[0]) << ".0f";
    ssDouble << static_cast<double>(in[0]) << ".0";

    display(ssChar, ssInt, ssFloat, ssDouble);
}

void    convertFromInt(const std::string &in)
{
    std::stringstream   ssChar;
    std::stringstream   ssInt;
	std::stringstream   ssFloat;
	std::stringstream   ssDouble;
    
    long long longValue = std::strtoll(in.c_str(), NULL, 10);
    if (longValue > std::numeric_limits<int>::max() || longValue < std::numeric_limits<int>::min())
        throw std::invalid_argument("int overflow");
    int intValue = static_cast<int>(longValue);

    if (std::isprint(intValue))
        ssChar << "'" << static_cast<char>(intValue) << "'";
    else if (isascii(intValue))
        ssChar << "non displayable";
    else
        ssChar << "impossible";
    ssInt << intValue;
    ssFloat << static_cast<float>(intValue) << ".0f";
    ssDouble << static_cast<double>(intValue) << ".0";

    display(ssChar, ssInt, ssFloat, ssDouble);
}

void    convertFromFloat(const std::string &in)
{
    std::stringstream   ssChar;
    std::stringstream   ssInt;
	std::stringstream   ssFloat;
	std::stringstream   ssDouble;

    double doubleValue = std::strtod(in.c_str(), NULL);
    if (doubleValue > std::numeric_limits<float>::max() || doubleValue < std::numeric_limits<float>::min())
        throw std::invalid_argument("float overflow");
    float floatValue = static_cast<float>(doubleValue);
    
    if (std::isprint(floatValue))
        ssChar << "'" << static_cast<char>(floatValue) << "'";
    else if (isascii(floatValue))
        ssChar << "non displayable";
    else
        ssChar << "impossible";
    if (doubleValue > std::numeric_limits<int>::max() || doubleValue < std::numeric_limits<int>::min())
        ssInt << "impossible";
    else
        ssInt << static_cast<int>(doubleValue);
    if (floatValue - static_cast<int>(doubleValue) == 0)
    {
        ssFloat << floatValue << ".0f";
        ssDouble << static_cast<double>(floatValue) << ".0";
    }
    else
    {
        ssFloat << floatValue << "f";
        ssDouble << static_cast<double>(floatValue);
    }

    display(ssChar, ssInt, ssFloat, ssDouble);
}

void    convertFromDouble(const std::string &in)
{
    std::stringstream   ssChar;
    std::stringstream   ssInt;
	std::stringstream   ssFloat;
	std::stringstream   ssDouble;

    long double longDoubleValue = std::strtold(in.c_str(), NULL);
    if (longDoubleValue > std::numeric_limits<double>::max() || longDoubleValue < std::numeric_limits<double>::min())
        throw std::invalid_argument("double overflow");
    double  doubleValue = static_cast<double>(longDoubleValue);

    if (std::isprint(doubleValue))
        ssChar << "'" << static_cast<char>(doubleValue) << "'";
    else if (isascii(doubleValue))
        ssChar << "non displayable";
    else
        ssChar << "impossible";
    if (doubleValue > std::numeric_limits<int>::max() || doubleValue < std::numeric_limits<int>::min())
        ssInt << "impossible";
    else
        ssInt << static_cast<int>(doubleValue);
    if (longDoubleValue > std::numeric_limits<float>::max() || longDoubleValue < std::numeric_limits<float>::min())
        ssFloat << "impossible";
    else if (doubleValue - static_cast<int>(doubleValue) == 0)
        ssFloat << static_cast<float>(doubleValue) << ".0f";
    else
        ssFloat << static_cast<float>(doubleValue) << "f";

    if (doubleValue - static_cast<int>(doubleValue) == 0)
        ssDouble << doubleValue << ".0";
    else
        ssDouble << doubleValue;
    
    display(ssChar, ssInt, ssFloat, ssDouble);
}

void    convertFromLiteral(const std::string &in)
{
    std::stringstream   ssChar;
    std::stringstream   ssInt;
	std::stringstream   ssFloat;
	std::stringstream   ssDouble;

    ssChar << "impossible";
    ssInt << "impossible";
    if (in == "-inff" || in == "-inf")
    {
        ssFloat << "-inff";
        ssDouble << "-inf";
    }
    else if (in == "+inff" || in == "+inf")
    {
        ssFloat << "+inff";
        ssDouble << "+inf";
    }
    else
    {
        ssFloat << "nanf";
        ssDouble << "nan";
    }

    display(ssChar, ssInt, ssFloat, ssDouble);
}


void	ScalarConverter::convert(const std::string &in)
{
    if (in.empty())
        throw std::invalid_argument("empty string");

    switch(checkType(in))
    {
        case CHAR:
            convertFromChar(in);
            break;
        case INT:
            convertFromInt(in);
            break;
        case FLOAT:
            convertFromFloat(in);
            break;
        case DOUBLE:
            convertFromDouble(in);
            break;
        case LITERAL:
            convertFromLiteral(in);
            break;
        case UNKNOWN:
            throw std::invalid_argument("invalid argument");
            break;
    }
}