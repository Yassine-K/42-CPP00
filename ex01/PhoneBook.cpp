/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 10:00:38 by ykhayri           #+#    #+#             */
/*   Updated: 2023/12/17 14:52:13 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	drawLine() {
	for (int i = 0; i < 45; i++)
		std::cout << "-";
	std::cout << std::endl;
}

void	row(std::string id, std::string f_name, std::string l_name, std::string nick) {
	unsigned int	j;
	std::string		tmp;

	for (int i = 0; i < 4; i++) {
		j = -1;
		if (!i)
			tmp = id;
		if (i == 1)
			tmp = f_name;
		if (i == 2)
			tmp = l_name;
		if (i == 3)
			tmp = nick;
		if (tmp.length() > 10) {
			tmp = tmp.substr(0, 10);
			tmp[9] = '.';
 		}
		std::cout << '|';
		while (++j < 10 - tmp.length())
			std::cout << ' ';
		std::cout << tmp;
	}
	std::cout << '|';
	std::cout << std::endl;
	drawLine();
}

void	Contact::set_att(int k, std::string val) {
	switch (k){
		case 1:
			firstName = val;
			break;
		case 2:
			lastName = val;
			break;
		case 3:
			nickname = val;
			break;
		case 4:
			phoneNumber = val;
			break;
		case 5:
			darkestSecret = val;
			break;
	}
}

std::string Contact::get_att(int k) {
	switch (k){
		case 1:
			return (firstName);
		case 2:
			return (lastName);
		case 3:
			return (nickname);
		case 4:
			return (phoneNumber);
	}
	return (darkestSecret);
}

int	PhoneBook::is_valid_id(int id) {
	if (id == 1 && !Contacts[id - 1].get_att(1).length())
		return (-1);
	if (id > 8 || id < 1 || !Contacts[id - 1].get_att(1).length())
		return (0);
	return (1);
}

void PhoneBook::add() {
	int	i;
	std::string tmp;
	std::string elm[5] = {"First name:", "Last name:", "Nickname:", "Phone number:", "Darkest secret:"};

	i = 0;
	std::cin.ignore(1, '\n');
	while (i < 5)
	{
		std::cout << elm[i] << std::endl;
		getline(std::cin, tmp);
		Contacts[ind].set_att(i + 1, tmp);
		if (std::cin.eof())
			exit(0);
		if (!Contacts[ind].get_att(i + 1).length() && !std::cin.eof())
			continue;
		i++;
	}
	ind++;
	if (ind > 7)
		ind = 0;
}

void PhoneBook::search() {
	int					i;
	int					ind;
	std::string			id;

	i = -1;
	drawLine();
	row("index", "first name", "last name", "nickname");
	while (++i < 8 && Contacts[i].get_att(first_name).length()) {
		std::stringstream	to_s;
		to_s << i + 1;
		to_s >> id;
		row(id, Contacts[i].get_att(first_name), Contacts[i].get_att(last_name), Contacts[i].get_att(nickn));
	}
	if (is_valid_id(1) < 0) {
		std::cout << "No contact was found!" << std::endl;
		return ;
	}
	do {
		std::string str;
		std::cout << "Contact index:" << std::endl;
		std::cin >> str;
		std::stringstream ss(str);
		ss >> ind;
		if (std::cin.eof())
			exit(0);
	} while (!is_valid_id(ind));
	std::cout << "First name    : " << Contacts[--ind].get_att(first_name) << std::endl;
	std::cout << "Last name     : " << Contacts[ind].get_att(last_name) << std::endl;
	std::cout << "Nickname      : " << Contacts[ind].get_att(nickn) << std::endl;
	std::cout << "Phone Number  : " << Contacts[ind].get_att(phone_number) << std::endl;
	std::cout << "Darkest secret: " << Contacts[ind].get_att(darkest_secret) << std::endl;
}

int main() {
	PhoneBook	myBook;
	std::string	command;
	
	myBook.ind = 0;
	while (1)
	{
		std::cout << "What would you like to do?" << std::endl;
		std::cin >> command;
		if (std::cin.eof())
			break ;
		if (!command.compare("ADD"))
			myBook.add();
		else if (!command.compare("SEARCH"))
			myBook.search();
		else if (!command.compare("EXIT")) {
			std::cout << "--Wextra salutes you!" << std::endl;
			break;
		}
		else {
			std::cout << "Error: -> " << command << " <- is not a valid command!" << std::endl;
			std::cout << "Help: The only availabe commands are 'ADD', 'SEARCH', and 'EXIT'." << std::endl;
		}
	}
	return (0);
}