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