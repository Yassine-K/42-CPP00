/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 10:00:38 by ykhayri           #+#    #+#             */
/*   Updated: 2023/12/16 12:44:13 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

void	drawLine(){
	for (int i = 0; i < 45; i++)
		std::cout << "-";
	std::cout << std::endl;
}

void	row(std::string id, std::string f_name, std::string l_name, std::string nickname) {
	int			j;
	std::string	tmp;

	j = -1;
	for (int i = 0; i < 4; i++){
		if (!i)
			tmp = id;
		if (i == 1)
			tmp = f_name;
		if (i == 2)
			tmp = l_name;
		if (i == 3)
			tmp = nickname;
		std::cout << '|';
		while (++j < tmp.length())
	}
}

void PhoneBook::add(){
	int	i;

	i = 0;
	while (i < 6)
	{
		if (i == 0)
		{
			std::cout << "First name:" << std::endl;
			std::cin >> Contacts[ind].firstName;
			std::cout << Contacts[ind].firstName << std::endl;
			if (!Contacts[ind].firstName.length())
				continue;
		}
		if (i == 2)
		{
			std::cout << "Last name:" << std::endl;
			std::cin >> Contacts[ind].lastName;
			std::cout << Contacts[ind].lastName << std::endl;
			if (!Contacts[ind].lastName.length())
				continue;
		}
		if (i == 3)
		{
			std::cout << "Nickname:" << std::endl;
			std::cin >> Contacts[ind].nickname;
			std::cout << Contacts[ind].nickname << std::endl;
			if (!Contacts[ind].nickname.length())
				continue;
		}
		if (i == 4)
		{
			std::cout << "Phone number:" << std::endl;
			std::cin >> Contacts[ind].phoneNumber;
			std::cout << Contacts[ind].phoneNumber << std::endl;
			if (!Contacts[ind].phoneNumber.length() || Contacts[ind].phoneNumber.length() < 10)
				continue;
		}
		if (i == 5)
		{
			std::cout << "Darkest secre:" << std::endl;
			std::cin >> Contacts[ind].darkestSecret;
			std::cout << Contacts[ind].darkestSecret << std::endl;
			if (!Contacts[ind].darkestSecret.length())
				continue;
		}
		i++;
	}
	ind++;
	if (ind > 7)
		ind = 0;
}

void PhoneBook::search() {
	drawLine();
	row("index", "first name", "last name", "nickname");
}

int main()
{
	PhoneBook	myBook;
	std::string	command;
	
	myBook.ind = 0;
	while (1)
	{
		std::cout << "What would you like to do?" << std::endl;
		std::cin >> command;
			if (!command.compare("ADD"))
				myBook.add();
			else if (!command.compare("SEARCH"))
				myBook.search();
			else if (!command.compare("EXIT"))
				break;
			else {
				std::cout << "Error: -> " << command << " <- is not a valid command!" << std::endl;
				std::cout << "Help: The only availabe commands are 'ADD', 'SEARCH', and 'EXIT'." << std::endl;
			}
	}
	return 0;
}