/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 09:17:43 by abrisse           #+#    #+#             */
/*   Updated: 2023/08/28 09:17:44 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void)
{
	PhoneBook	phoneBook;
	std::string	in;
	int			index;

	while (in != "EXIT")
	{
		std::cout << "Enter a command (ADD, SEARCH or EXIT) > ";
		std::getline(std::cin, in);
		if (in == "ADD")
			phoneBook.addContact();
		else if (in == "SEARCH")
		{
			if (phoneBook.display())
			{
				std::cout << "Select an index > ";
				std::cin >> index;
				if (!std::cin)
				{
					std::cin.clear();
					std::cin >> in;
					std::cout << "No ! Enter a number please" << std::endl;
				}
				else if (index > 0 && index <= 8)
					phoneBook.getContact(index).display();
				else
					std::cout << "Invalid index" << std::endl;
				std::cin.ignore();
			}
		}
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return 0;
		}
	}
	return 0;
}