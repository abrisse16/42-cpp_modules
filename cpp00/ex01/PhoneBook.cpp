#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_size = 0;
}

PhoneBook::~PhoneBook(void)
{
}

Contact	PhoneBook::getContact(int index) const
{
	return _contacts[index - 1];
}

std::string	truncate(std::string str)
{
	if (str.size() > 10)
		return (str.substr(0, 9).append("."));
	return (str);
}

int	PhoneBook::display(void) const
{
	if (this->_size == 0)
	{
		std::cout << "PhoneBook empty" << std::endl;
		return 0;
	}
	std::cout << "|";
	std::cout << std::setw(10) << "INDEX" << "|";
	std::cout << std::setw(10) << "FIRST NAME" << "|";
	std::cout << std::setw(10) << "LAST NAME" << "|";
	std::cout << std::setw(10) << "NICKNAME" << "|";
	std::cout << std::endl;
	for (int i = 0; i < 8 && _contacts[i].getFirstName().length(); i++)
	{
		std::cout << "|";
		std::cout << std::setw(10) << i + 1 << "|";
		std::cout << std::setw(10) << truncate(_contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << truncate(_contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << truncate(_contacts[i].getNickname()) << "|";
		std::cout << std::endl;
	}
	return 1;
}

int	PhoneBook::getSize(void) const
{
	return _size;
}

void	PhoneBook::addContact(void)
{
	std::string	in;

	in = "";
	while (in == "")
	{
		std::cout << "Enter a first name: ";
		std::getline(std::cin, in);
		if (std::cin.eof())
			return;
		this->_contacts[this->_size % 8].setFirstName(in);
	}

	in = "";
	while (in == "")
	{
		std::cout << "Enter a last name: ";
		std::getline(std::cin, in);
		if (std::cin.eof())
			return;
		this->_contacts[this->_size % 8].setLastName(in);
	}

	in = "";
	while (in == "")
	{
		std::cout << "Enter a nickname: ";
		std::getline(std::cin, in);
		if (std::cin.eof())
			return;
		this->_contacts[this->_size % 8].setNickname(in);
	}

	in = "";
	while (in == "")
	{
		std::cout << "Enter a phone number: ";
		std::getline(std::cin, in);
		if (std::cin.eof())
			return;
		this->_contacts[this->_size % 8].setPhoneNumber(in);
	}

	in = "";
	while (in == "")
	{
		std::cout << "Enter a darkest secret: ";
		std::getline(std::cin, in);
		if (std::cin.eof())
			return;
		this->_contacts[this->_size % 8].setDarkestSecret(in);
	}

	this->_size++;

}