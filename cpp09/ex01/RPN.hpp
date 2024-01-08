/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 03:01:33 by abrisse           #+#    #+#             */
/*   Updated: 2024/01/08 04:23:52 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <stack>

class RPN
{
	public:

		RPN();
		RPN(RPN const &);
		~RPN();
		RPN & operator=(RPN const &);

		std::string const & getInput() const;

		void	addInput(std::string const & input);
		int		calculate(void);
		int		removeTop(void);

		int		doOperation(std::string op, int a, int b);
		int		doAddition(int a, int b);
		int		doSubstraction(int a, int b);
		int		doMultiplication(int a, int b);
		int		doDivision(int a, int b);

		class	NotEnoughOperandsException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class	DivisionByZeroException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
	
	private:

		std::string		_input;
		std::stack<int>	_stack;

};