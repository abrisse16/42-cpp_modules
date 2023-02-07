/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 22:30:17 by abrisse           #+#    #+#             */
/*   Updated: 2023/02/07 23:11:45 by abrisse          ###   ########.fr       */
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
		Cat( Cat const & );
		Cat &	operator=( Cat const & );
		~Cat( void );

		void	makeSound( void ) const;
};

#endif