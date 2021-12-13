/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 21:34:40 by rmander           #+#    #+#             */
/*   Updated: 2021/12/13 03:41:25 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
		return (EXIT_SUCCESS);
	}
	std::string curr;
	for (int i = 1; i < argc; ++i)
	{
		curr = argv[i];
		for (size_t j = 0; j < curr.length(); ++j)
			std::cout<<static_cast<char>(std::toupper(curr[j]));
	}
	std::cout<<std::endl;
	return (EXIT_SUCCESS);
}

