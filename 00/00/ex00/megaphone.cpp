/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 21:34:40 by rmander           #+#    #+#             */
/*   Updated: 2021/12/11 21:39:06 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char *argv[])
{
	std::string input{};

	std::cin>>input;

	for (size_t i = 0; i < input.length(); ++i)
		std::cout<<std::toupper(static_cast<int>(input[i]));

	std::cout<<std::endl;
	return (EXIT_SUCCESS);
}
