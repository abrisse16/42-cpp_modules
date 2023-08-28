/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 09:20:17 by abrisse           #+#    #+#             */
/*   Updated: 2023/08/28 09:20:18 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook(void);
	~PhoneBook(void);

	void	addContact(void);
	int		display(void) const;
	int		getSize(void) const;
	Contact	getContact(int index) const;

private:
	Contact	_contacts[8];
	int		_size;
};

#endif