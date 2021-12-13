/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 03:42:25 by rmander           #+#    #+#             */
/*   Updated: 2021/12/13 23:34:29 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"

# define PHONEBOOK_CAPACITY	8

# define PROMPT					"> "

# define SH_COLOR_WHITE		"\033[37m"
# define SH_COLOR_BLUE		"\033[34m"
# define SH_COLOR_PURPLE	"\033[35m"
# define SH_COLOR_RED			"\033[31m"
# define SH_COLOR_YELLOW	"\033[33m"
# define SH_COLOR_GREEN		"\033[32m"
# define SH_COLOR_RESET		"\033[m"
# define SH_COLOR_BOLD		"\033[1m"

class PhoneBook {

public:
	PhoneBook(void);
	~PhoneBook(void);

	void add(Contact contact);
	Contact* search(size_t index) const;
private:
	const size_t	_capacity;
	Contact _contacts[_capacity];
	size_t	_size;
	bool		_overflow;
};

#endif // PHONEBOOK_H
