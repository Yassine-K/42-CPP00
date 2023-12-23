/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:55:01 by ykhayri           #+#    #+#             */
/*   Updated: 2023/12/23 15:57:26 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int ac, char **av)
{
	std::string tmp;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < ac; i++)
		{
			tmp = av[i];
			for (unsigned int j = 0; j < tmp.length(); j++)
			{
				std::cout << (char) toupper(av[i][j]);
			}
		}
	}
	std::cout << std::endl;
    return 0;
}