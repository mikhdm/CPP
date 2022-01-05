/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 23:28:03 by rmander           #+#    #+#             */
/*   Updated: 2022/01/06 00:03:11 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

# define SH_COLOR_WHITE		"\033[37m"
# define SH_COLOR_BLUE		"\033[34m"
# define SH_COLOR_PURPLE	"\033[35m"
# define SH_COLOR_RED			"\033[31m"
# define SH_COLOR_YELLOW	"\033[33m"
# define SH_COLOR_GREEN		"\033[32m"
# define SH_COLOR_RESET		"\033[m"
# define SH_COLOR_BOLD		"\033[1m"


class Animal {
 public:
  Animal(void);
  Animal(Animal const& instance);
  virtual ~Animal(void);
  Animal& operator=(Animal const& instance);

  std::string const& getType(void) const;
  void setType(std::string const& newType);
  virtual void makeSound(void) const;
  static void log(std::string const& message, std::string const& color);
 protected:
  Animal(std::string const& ty);
  std::string type;
};
  
# endif // ANIMAL_HPP
