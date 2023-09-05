/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 22:30:17 by abrisse           #+#    #+#             */
/*   Updated: 2023/09/06 00:06:49 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat( void );
		Cat( Cat const & src );
		Cat &	operator=( Cat const & rhs );
		~Cat( void );

		void	makeSound( void ) const;
};

#endif