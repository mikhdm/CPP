/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 03:41:59 by rmander           #+#    #+#             */
/*   Updated: 2021/12/13 05:19:55 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <string>

class Contact {
public:
	Contact();
	~Contact();
	Contact(Contact &contact);
	Contact &operator=(Contact &contact);

	std::string &getFirstName();
	void setFirstName(std::string &value);

	std::string &getLastName();
	void setLastName(std::string &value);

	std::string &getNickname();
	void setNickname(std::string &value);

	std::string &getPhoneNumber();
	void setPhoneNumber(std::string &value);

	std::string &getDarkestSecret();
	void setDarkestSecret(std::string &value);

private:
	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _phone_number;
	std::string _darkest_secret;
};

#endif // CONTACT_H
