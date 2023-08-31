/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CopyAndReplace.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:47:29 by abrisse           #+#    #+#             */
/*   Updated: 2023/08/31 15:43:07 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdio>
#include <iostream>
#include "CopyAndReplace.hpp"

#ifndef DEBUG

CopyAndReplace::CopyAndReplace( std::string const & filename ) : _ifs(filename.c_str()), _ofs((filename + ".replace").c_str())
{
	if (!_ifs)
	{
		std::cerr << "Error: " << filename << ": no such file or directory" << std::endl;
		if (_ofs)
			std::remove((filename + ".replace").c_str());
	}
	if (!_ofs)
		std::cerr << "Error: " << filename << ".replace: permission denied" << std::endl;
}

CopyAndReplace::~CopyAndReplace( void )
{
	_ifs.close();
	_ofs.close();
}

#else

CopyAndReplace::CopyAndReplace( std::string const & filename ) : _ifs(filename), _ofs(filename + ".replace")
{
	std::cout << "Constructor called" << std::endl;
	if (!_ifs)
	{
		std::cerr << "Error: " << filename << " is missing" << std::endl;
		if (_ofs)
			std::remove((filename + ".replace").c_str());
	}
	if (!_ofs)
		std::cerr << "Error: " << filename << ".replace no permission" << std::endl;
}

CopyAndReplace::~CopyAndReplace( void )
{
	std::cout << "Destructor called" << std::endl;
	_ifs.close();
	_ofs.close();
}

#endif

void	CopyAndReplace::replace( std::string const & oldString, std::string const & newString )
{
	std::string	line;

	while (std::getline(_ifs, line))
	{
		while (!line.empty())
		{
			std::size_t pos = line.find(oldString);
			_ofs << line.substr(0, pos);
			if (pos >= line.size())
				break;
			_ofs << newString;
			line = line.substr(pos + oldString.size());
		}
		_ofs << std::endl;
	}
}