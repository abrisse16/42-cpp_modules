/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 09:05:19 by abrisse           #+#    #+#             */
/*   Updated: 2023/08/28 09:12:26 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	this->_firstName = "";
	this->_lastName = "";
	this->_nickname = "";
	this->_phoneNumber = "";
	this->_darkestSecret = "";
}

Contact::~Contact(void)
{
}

void	Contact::display(void) const
{
	if (!getFirstName().length())
	{
		std::cout << "Invalid index, this contact doesn't exist" << std::endl;
		return;
	}
	std::cout << "First Name: " << getFirstName() << std::endl;
	std::cout << "Last Name: " << getLastName() << std::endl;
	std::cout << "Nickname: " << getNickname() << std::endl;
	std::cout << "Phone number: " << getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << getDarkestSecret() << std::endl;
}

std::string	Contact::getFirstName(void) const
{
	return (this->_firstName);
}

std::string	Contact::getLastName(void) const
{
	return (this->_lastName);
}
	
std::string	Contact::getNickname(void) const
{
	return (this->_nickname);
}

std::string	Contact::getPhoneNumber(void) const
{
	return (this->_phoneNumber);
}

std::string	Contact::getDarkestSecret(void) const
{
	return (this->_darkestSecret);
}

void		Contact::setFirstName(std::string firstName)
{
	this->_firstName = firstName;
}

void		Contact::setLastName(std::string lastName)
{
	this->_lastName = lastName;
}

void		Contact::setNickname(std::string nickname)
{
	this->_nickname = nickname;
}

void		Contact::setPhoneNumber(std::string phoneNumber)
{
	this->_phoneNumber = phoneNumber;
}

void		Contact::setDarkestSecret(std::string darkestSecret)
{
	this->_darkestSecret = darkestSecret;
}