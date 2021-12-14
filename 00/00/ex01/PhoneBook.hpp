/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 03:42:25 by rmander           #+#    #+#             */
/*   Updated: 2021/12/14 16:47:26 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"

# define PHONEBOOK_CAPACITY	8
# define PHONEBOOK_COLSIZE	10

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

	size_t getSize(void) const;
	void add(Contact contact);
	Contact search(size_t index) const;
private:
	Contact _contacts[PHONEBOOK_CAPACITY];
	size_t	_size;
	bool		_overflow;
};


std::ostream& operator<<(std::ostream& o, const PhoneBook& phonebook);

#endif // PHONEBOOK_H

