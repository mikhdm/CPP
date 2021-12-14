/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:57:26 by rmander           #+#    #+#             */
/*   Updated: 2021/12/14 20:52:55 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#include <cmath>
#include <iostream>


static void showmessage(std::string str, bool endl) {
		std::cout<<SH_COLOR_BOLD<<SH_COLOR_GREEN<<str<<SH_COLOR_RESET;
		if (endl)
			std::cout<<std::endl;
}


static void showerror(std::string str) {
	std::cerr<<SH_COLOR_BOLD<<SH_COLOR_RED<<str
		<<SH_COLOR_RESET<<std::endl;
}


static void showexit(void) {
	std::cout<<SH_COLOR_BOLD<<SH_COLOR_GREEN<<"Exit"<<SH_COLOR_RESET<<std::endl;
}


static bool iseof(bool check) {
	if (check)
		showexit();
	return check;
}


static bool digits_only(std::string const& str) {
	for (size_t i = 0; i < str.length(); ++i) {
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
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
		showmessage(prompt, false);
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

static void search(PhoneBook& phonebook) {
	std::string buff;
	double			dvalue;
	Contact			contact;

	while (true) {
		showmessage("index> ", false);
		std::getline(std::cin, buff);
		if (iseof(std::cin.eof())) {
			exit(EXIT_SUCCESS);
		}
		if (buff.empty())
			continue ;
		if (!digits_only(buff)) {
			showerror("Enter valid value");
			continue ;
		}
		dvalue = std::strtod(buff.c_str(), nullptr);
		if (dvalue == HUGE_VAL) {
			showerror("Enter valid value");
			continue ;
		}
		contact = phonebook.search(static_cast<size_t>(dvalue));
		if (!contact.getFallback()) {
			std::cout<<contact;
			break ;
		}
		showerror("Contact not found");
		break ;
	}
}

int main(void) {
	std::string buff;
	PhoneBook		phonebook;
	
	while (true) {
		showmessage(PROMPT, false);
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
			if (phonebook.getSize() == 0)
			{
				showmessage("Phonebook is empty yet", true);
				continue ;
			}
			std::cout<<phonebook;
			search(phonebook);
			continue ;
		}
		else if (buff == "EXIT") {
			showexit();
			break ;
		}
	}
	return (EXIT_SUCCESS);
}

