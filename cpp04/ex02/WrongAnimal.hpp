/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 22:30:17 by abrisse           #+#    #+#             */
/*   Updated: 2023/09/06 00:23:28 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal
{
	protected:
		std::string	_type;
		
	public:
		WrongAnimal( void );
		WrongAnimal( WrongAnimal const & src );
		WrongAnimal &	operator=( WrongAnimal const & rhs );
		virtual ~WrongAnimal( void );

		void			makeSound( void ) const;
		std::string		getType( void ) const;
};

#endif