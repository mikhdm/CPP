/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:57:26 by rmander           #+#    #+#             */
/*   Updated: 2021/12/13 23:34:31 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

# define ST_BASE 0
# define ST_ADD	 1
# define ST_SEARCH 2

void	setprompt(std::string str) {
	std::cout<<SH_COLOR_GREEN<<str<<SH_COLOR_RESET;
}

void	add() {
	Contact			contact;

	std::string buff;
	std::string prompt;

	while (true) {
		std::cout<<prompt;
		std::getline(std::cin, buff);
		if (std::cin.eof()) {
			std::cout<<std::endl<<SH_COLOR_BOLD<<SH_COLOR_GREEN<<"Exit"<<SH_COLOR_RESET<<std::endl;
			break ;
		}

	}

	if (index == 1)
		contact.setFirstName(buff);
	else if (index == 2)
		contact.setLastName(buff);
	else if (index == 3)
		contact.setNickname(buff);
	else if (index == 4)
		contact.setPhoneNumber(buff);
	else if (index == 5)
		contact.setDarkestSecret(buff);
}

int main(void) {

	std::string buff;
	PhoneBook		phonebook;
	Contact			contact;
	int					state;
	std::string	prompt;
	int					index;
	
	state = ST_BASE;
	prompt = PROMPT;
	while (true) {
		setprompt(str);

		std::getline(std::cin, buff);
		if (std::cin.eof()) {
			std::cout<<std::endl<<SH_COLOR_BOLD<<SH_COLOR_GREEN<<"Exit"<<SH_COLOR_RESET<<std::endl;
			break ;
		}
		if (buff.empty())
				continue ;

		if (state == ST_BASE) {
				if ((buff != "EXIT") && (buff != "ADD") && (buff != "SEARCH")) {
					std::cout<<SH_COLOR_BOLD<<SH_COLOR_RED<<"Enter valid command"
						<<SH_COLOR_RESET<<std::endl;
					continue ;
				}
				if (buff == "ADD") {
					prompt = "add (first name)> ";
					state = ST_ADD;
					continue ;
				}
				else if (buff == "SEARCH") {
					prompt = "search> ";
					state = ST_SEARCH;
					continue ;
				}
				else if (buff == "EXIT") {
					std::cout<<SH_COLOR_BOLD<<SH_COLOR_GREEN<<"Exit"<<SH_COLOR_RESET<<std::endl;
					break ;
				}
		} else if (state == ST_ADD) {
			contact = readContact();
			phonebook.add(contact);
		} else if (state == ST_SEARCH) {
			phonebook.search(index);
		}
	}
	return (EXIT_SUCCESS);
}
