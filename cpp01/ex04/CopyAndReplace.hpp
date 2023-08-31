/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CopyAndReplace.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:45:04 by abrisse           #+#    #+#             */
/*   Updated: 2023/08/31 15:41:20 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COPYANDREPLACE_HPP
#define COPYANDREPLACE_HPP

#include <string>
#include <fstream>

class	CopyAndReplace
{
	public :
		CopyAndReplace( std::string const & filename );
		~CopyAndReplace( void );
		void replace( std::string const & oldString,  std::string const & newString );
	
	private :
		std::ifstream	_ifs;
		std::ofstream	_ofs;
};

#endif