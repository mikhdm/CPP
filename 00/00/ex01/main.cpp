/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:57:26 by rmander           #+#    #+#             */
/*   Updated: 2021/12/14 12:30:08 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

static void showprompt(std::string str) {
	std::cout<<SH_COLOR_GREEN<<str<<SH_COLOR_RESET;
}

static void showerror(std::string str) {
	std::cout<<SH_COLOR_BOLD<<SH_COLOR_RED<<str
		<<SH_COLOR_RESET<<std::endl;
}

static void showexit(void) {
	std::cout<<std::endl<<SH_COLOR_BOLD<<SH_COLOR_GREEN<<"Exit"<<SH_COLOR_RESET<<std::endl;
}

static bool iseof(bool check)
{
	if (check)
		showexit();
	return check;
}

static void	add(PhoneBook &phonebook) {
	Contact contact;
	std::string buff;	
	std::string prompt;
	size_t	i;
	size_t	nreads;

	i = 0;	
	nreads = 5;
	prompt = "add (first name)> ";
	while (i < nreads)
	{
		showprompt(prompt);
		std::getline(std::cin, buff);
		if (iseof(std::cin.eof())) {
			exit(EXIT_SUCCESS);
		}
		if (buff.empty())
			continue ;

		switch (i) {
			case 0:
				contact.setFirstName(buff);
				prompt = "add (last name)> ";
				break;
			case 1:
				contact.setLastName(buff);
				prompt = "add (nickname)> ";
				break;
			case 2:
				contact.setNickname(buff);
				prompt = "add (phone number)> ";
				break;
			case 3:
				contact.setPhoneNumber(buff);
				prompt = "add (darkest secret)> ";
				break;
			case 4:
				contact.setDarkestSecret(buff);
				break;
		}
		++i;
	}
	phonebook.add(contact);
	return;
}

int main(void) {
	std::string buff;
	PhoneBook		phonebook;
	
	while (true) {
		showprompt(PROMPT);

		std::getline(std::cin, buff);
		if (iseof(std::cin.eof())) {
			break ;
		}
		if (buff.empty())
				continue ;

		if ((buff != "EXIT") && (buff != "ADD") && (buff != "SEARCH")) {
			showerror("Enter valid command");
			continue ;
		}
		if (buff == "ADD") {
			add(phonebook);
			continue ;
		}
		else if (buff == "SEARCH") {
			/* search(phonebook); */
			std::cout<<phonebook;
			continue ;
		}
		else if (buff == "EXIT") {
			showexit();
			break ;
		}
	}
	return (EXIT_SUCCESS);
}
