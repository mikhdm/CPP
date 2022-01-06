/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 23:28:03 by rmander           #+#    #+#             */
/*   Updated: 2022/01/06 19:39:52 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>

# define SH_COLOR_WHITE		"\033[37m"
# define SH_COLOR_BLUE		"\033[34m"
# define SH_COLOR_PURPLE	"\033[35m"
# define SH_COLOR_RED			"\033[31m"
# define SH_COLOR_YELLOW	"\033[33m"
# define SH_COLOR_GREEN		"\033[32m"
# define SH_COLOR_RESET		"\033[m"
# define SH_COLOR_BOLD		"\033[1m"


class AAnimal {
 public:
  AAnimal(void);
  AAnimal(AAnimal const& instance);
  virtual ~AAnimal(void);
  AAnimal& operator=(AAnimal const& instance);

  std::string const& getType(void) const;
  void setType(std::string const& newType);
  virtual void makeSound(void) const = 0;
  static void log(std::string const& message, std::string const& color);
 protected:
  AAnimal(std::string const& ty);
  std::string type;
};
  
# endif // AANIMAL_HPP
