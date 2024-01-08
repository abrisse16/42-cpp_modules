/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 23:55:08 by abrisse           #+#    #+#             */
/*   Updated: 2024/01/08 05:02:43 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::ifstream	ifs("data.csv");
	std::string		line;

	if (!ifs || !std::getline(ifs, line))
		throw DatabaseException();
	
	while (std::getline(ifs, line))
	{
		std::stringstream	ss(line);
		std::string			token;

		if(!std::getline(ss, token, ','))
			throw DatabaseErrorException();
		std::string	date = token;
		if (date.empty())
			throw DatabaseErrorException();

		if(!std::getline(ss, token, ','))
			throw DatabaseErrorException();
		double		exchange_rate = std::strtod(token.c_str(), NULL);

		//_database.insert(std::pair<std::string, double>(date, exchange_rate));
		_database[date] = exchange_rate;
	}
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src) : _database(src._database) { }

BitcoinExchange::~BitcoinExchange() { }


BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & rhs)
{
	if (this != &rhs)
	{
		for (_itDatabase it = _database.begin(); it != _database.end(); ++it)
			_database.insert(*it);
	}
	return *this;
}

int	countColumns(std::string const & line, char delim)
{
	int					count = 0;
	std::string			_token;
	std::stringstream	ss(line);

	while (std::getline(ss, _token, delim))
		count++;
	return count;
}

std::string& trim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
{
	str.erase(0, str.find_first_not_of(chars));
	str.erase(str.find_last_not_of(chars) + 1);
	return str;
}

bool	isValidDate(std::string const & date)
{
	std::stringstream	ss(date);
	std::string			token;

	if (countColumns(date, '-') != 3)
		return false;

	std::getline(ss, token, '-');
	long	year = std::strtol(token.c_str(), NULL, 10);
	if (year < 2009 || year > 2100)
		return false;
	
	std::getline(ss, token, '-');
	long	month = std::strtol(token.c_str(), NULL, 10);
	if (month < 1 || month > 12)
		return false;

	std::getline(ss, token, '-');
	long	day = std::strtol(token.c_str(), NULL, 10);
	if (day < 1 || day > 31)
		return false;

	return true;
}

void	BitcoinExchange::parseFile(std::string const & inputFileName)
{
	std::ifstream	ifs(inputFileName.c_str());
	std::string		line;

	if (!ifs || !std::getline(ifs, line))
		throw FileException("nvalid or missing input file.");
	if (countColumns(line, '|') != 2)
		throw FileException("nvalid or missing input file.");
	
	while (std::getline(ifs, line))
	{
		try
		{
			std::stringstream	ss(line);
			std::string			token;

			if(!std::getline(ss, token, '|'))
				throw FileException("missing date");
			std::string	date(trim(token));
			if (date.empty())
				throw FileException("missing date");
			if (!isValidDate(date))
				throw FileException("bad input => " + date);
			
			if(!std::getline(ss, token, '|'))
				throw FileException("missing value");
			double	value = std::strtod(trim(token).c_str(), NULL);
			if (value < 0)
				throw FileException("not a positive number");
			if (value > 1000)
				throw FileException("too large a number");

			double convertedValue = convert(date, value);
			std::cout << date << " => " << value << " = " << convertedValue << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}

double	BitcoinExchange::convert(std::string const & date, double value)
{
	_itDatabase	it = _database.lower_bound(date);

	if (it == _database.begin())
		throw FileException("no data before this date");
	if (it == _database.end() || (it != _database.end() && it->first != date))
		it--;
	return value * it->second;
}


const char* BitcoinExchange::DatabaseException::what() const throw()
{
	return "Error: No database found.";
}

const char* BitcoinExchange::DatabaseErrorException::what() const throw()
{
	return "Error: Database error.";
}

const char* BitcoinExchange::FileException::what() const throw()
{
	return _arg.c_str();
}

