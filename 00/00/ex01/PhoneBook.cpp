/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 05:23:29 by rmander           #+#    #+#             */
/*   Updated: 2021/12/13 23:34:27 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#include <cstddef>

#include "Contact.hpp" 

PhoneBook::PhoneBook(void) : _capacity(PHONEBOOK_CAPACITY), _size(0), _overflow(false) {}

PhoneBook::~PhoneBook(void) {}

void			PhoneBook::add(Contact contact) {
	if (_size == _capacity)
	{
		_overflow = true;
		_size = 0;
	}
	_contacts[_size] = contact;
	++_size;
}

Contact*	PhoneBook::search(size_t index) const {
	if (_overflow)
		return _contacts[index];
	if (index >= _size)
		return NULL;
	return _contacts[index];
