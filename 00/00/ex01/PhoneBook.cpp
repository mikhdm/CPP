/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 05:23:29 by rmander           #+#    #+#             */
/*   Updated: 2021/12/14 16:47:18 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#include <cstddef>
#include <iomanip>
#include <iostream>

#include "Contact.hpp"


PhoneBook::PhoneBook(void) : _size(0), _overflow(false) {}


PhoneBook::~PhoneBook(void) {}


size_t PhoneBook::getSize(void) const {
	if (_overflow)
		return (PHONEBOOK_CAPACITY);
	return _size;
}


void			PhoneBook::add(Contact contact) {
	if (_size == PHONEBOOK_CAPACITY)
	{
		_overflow = true;
		_size = 0;
	}
	_contacts[_size] = contact;
	++_size;
}


Contact PhoneBook::search(size_t index) const {
	Contact empty;
	empty.setFallback(true);
	if (index >= PHONEBOOK_CAPACITY)
		return (empty);
	if (_overflow)
		return _contacts[index];
	if (index >= _size)
		return (empty);
	return _contacts[index];
}


static std::string truncate(std::string str) { 
	std::string copy;
	if (str.length() >= PHONEBOOK_COLSIZE)
	{
		copy = str;
		copy.resize(10);
		copy.replace(9, 1, ".");
		return copy;
	}
	return str;
}


std::ostream& operator<<(std::ostream& o, PhoneBook const& phonebook) {
	Contact contact;

	std::cout<<SH_COLOR_YELLOW<<"|"<<std::setw(PHONEBOOK_COLSIZE)<<"index"
		<<"|"<<std::setw(PHONEBOOK_COLSIZE)<<"first name"
		<<"|"<<std::setw(PHONEBOOK_COLSIZE)<<"last name"
		<<"|"<<std::setw(PHONEBOOK_COLSIZE)<<"nickname"<<"|"
		<<SH_COLOR_RESET<<std::endl;

	for (size_t i = 0; i < phonebook.getSize(); ++i) {
		contact = phonebook.search(i);
		std::cout<<SH_COLOR_PURPLE<<"|"<<std::setw(PHONEBOOK_COLSIZE)<<i
			<<"|"<<std::setw(PHONEBOOK_COLSIZE)<<truncate(contact.getFirstName())
			<<"|"<<std::setw(PHONEBOOK_COLSIZE)<<truncate(contact.getLastName())
			<<"|"<<std::setw(PHONEBOOK_COLSIZE)<<truncate(contact.getNickname())<<"|"
			<<SH_COLOR_RESET<<std::endl;
	}
	return o;
}
