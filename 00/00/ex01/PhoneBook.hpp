/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 03:42:25 by rmander           #+#    #+#             */
/*   Updated: 2021/12/13 05:21:09 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# define CONTACT_COUNT	8

#include "Contact.hpp"

class PhoneBook {
public:

private:
	Contact _contacts[CONTACT_COUNT];
};

#endif // PHONEBOOK_H
