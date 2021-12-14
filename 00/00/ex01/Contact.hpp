/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 03:41:59 by rmander           #+#    #+#             */
/*   Updated: 2021/12/14 16:47:21 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <string>
#include <iomanip>
#include <iostream>


class Contact {

 public:
	Contact(void);
	~Contact(void);

	std::string getFirstName(void) const;
	void setFirstName(std::string& value);

	std::string getLastName(void) const;
	void setLastName(std::string& value);

	std::string getNickname(void) const;
	void setNickname(std::string& value);

	std::string getPhoneNumber(void) const;
	void setPhoneNumber(std::string& value);

	std::string getDarkestSecret(void) const;
	void setDarkestSecret(std::string& value);

	bool getFallback(void) const;
	void setFallback(bool value);

 private:
	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _phone_number;
	std::string _darkest_secret;
	bool				_fallback;
};


std::ostream& operator<<(std::ostream& o, Contact const& contact);

#endif // CONTACT_H

