/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 03:16:40 by abrisse           #+#    #+#             */
/*   Updated: 2024/01/08 05:02:26 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <sstream>
#include <iostream>

RPN::RPN() : _input("") { }

RPN::RPN(RPN const & src) : _input(src._input), _stack(src._stack) { }

RPN::~RPN() { }

RPN & RPN::operator=(RPN const & rhs) {
	if (this != &rhs)
	{
		this->_input = rhs._input;
		this->_stack = rhs._stack;
	}
	return *this;
}

std::string const & RPN::getInput() const
{
	return _input;
}

void	RPN::addInput(std::string const & input)
{
	if (_input.empty())
		_input = input;
	else
		_input += " " + input;
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

bool	isOperator(std::string const & str)
{
	if (str.length() != 1)
		return false;
	
	std::string	operators[] = {"+", "-", "*", "/"};

	for (int i = 0; i < 4; i++)
	{
		if (str == operators[i])
			return true;
	}
	return false;
}

int		RPN::calculate(void)
{
	if (_input.empty())
		throw std::invalid_argument("Error: empty input");

	std::stringstream	ss(_input);
	std::string			token;

	while (ss >> token)
	{
		if (isInt(token))
		{
			long	longValue = std::strtol(token.c_str(), NULL, 10);
			if (longValue > 9 || longValue < 0)
				throw std::invalid_argument("Error: invalid value");
			int	value = static_cast<int>(longValue);
			_stack.push(value);
		}
		else if (isOperator(token))
		{
			if (_stack.size() < 2)
				throw NotEnoughOperandsException();
			_stack.push(doOperation(token, removeTop(), removeTop()));
		}
		else
			throw std::invalid_argument("Error: invalid value");
	}
	if (_stack.size() != 1)
		throw std::invalid_argument("Error: not enough arguments");
	return	_stack.top();
}

int		RPN::removeTop(void)
{
	int	ret = _stack.top();
	_stack.pop();
	return ret;
}

int		RPN::doOperation(std::string op, int a, int b)
{
	static const struct
	{
		int			(RPN::*func)(int, int);
		std::string	token;
	} operations[4] = {
		{&RPN::doAddition, "+"},
		{&RPN::doSubstraction, "-"},
		{&RPN::doMultiplication, "*"},
		{&RPN::doDivision, "/"}
	};

	for (int i = 0; i < 4; i++)
	{
		if (op == operations[i].token)
			return (this->*(operations[i].func))(a, b);
	}
	throw std::invalid_argument("Error: invalid value");
}

int		RPN::doAddition(int a, int b)
{
	return b + a;
}

int		RPN::doSubstraction(int a, int b)
{
	return b - a;
}

int		RPN::doMultiplication(int a, int b)
{
	return b * a;
}

int		RPN::doDivision(int a, int b)
{
	if (a == 0)
		throw DivisionByZeroException();
	return b / a;
}

const char* RPN::NotEnoughOperandsException::what() const throw()
{
	return "Error: not enough operands";
}

const char* RPN::DivisionByZeroException::what() const throw()
{
	return "Error: division by zero";
}