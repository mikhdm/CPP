/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 05:23:27 by rmander           #+#    #+#             */
/*   Updated: 2021/12/13 06:58:12 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {}
Contact::~Contact(void) {}

std::string Contact::getFirstName() const {
	return _first_name;
}

void Contact::setFirstName(std::string& value) {
	_first_name = value;
}

std::string Contact::getLastName() const {
	return _last_name;
}

void Contact::setLastName(std::string& value) {
	_last_name = value;
}

std::string Contact::getNickname() const {
	return _nickname;
}

void Contact::setNickname(std::string& value) {
	_nickname = value;
}

std::string Contact::getPhoneNumber() const {
	return _phone_number;
}

void Contact::setPhoneNumber(std::string& value) {
	_phone_number = value;
}

std::string Contact::getDarkestSecret() const {
	return _darkest_secret; 
}

void Contact::setDarkestSecret(std::string& value) {
	_darkest_secret = value;
}

