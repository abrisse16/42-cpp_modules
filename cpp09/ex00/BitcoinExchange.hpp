/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 23:52:25 by abrisse           #+#    #+#             */
/*   Updated: 2024/01/08 02:30:00 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <string>

class BitcoinExchange
{
	public:

		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &);
		~BitcoinExchange();
		BitcoinExchange & operator=(BitcoinExchange const &);

		class DatabaseException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class DatabaseErrorException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class FileException : public std::exception
		{
			public:
				~FileException() throw() { }
				explicit FileException(std::string const & arg) throw()
					: _arg("Error: " + arg)
				{}
				FileException(FileException const & oth) throw()
					: _arg(oth._arg)
				{}
				virtual const char* what() const throw();

			private:
				std::string _arg;
		};

		void	parseFile(std::string const & inputFileName);
		double	convert(std::string const & date, double value);


	private:
		std::map<std::string, double>	_database;
		typedef std::map<std::string, double>::iterator	_itDatabase;
};