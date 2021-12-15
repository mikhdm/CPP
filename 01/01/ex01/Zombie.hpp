/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:31:27 by rmander           #+#    #+#             */
/*   Updated: 2021/12/15 15:29:07 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>

# define SH_COLOR_WHITE		"\033[37m"
# define SH_COLOR_BLUE		"\033[34m"
# define SH_COLOR_PURPLE	"\033[35m"
# define SH_COLOR_RED			"\033[31m"
# define SH_COLOR_YELLOW	"\033[33m"
# define SH_COLOR_GREEN		"\033[32m"
# define SH_COLOR_RESET		"\033[m"
# define SH_COLOR_BOLD		"\033[1m"


class Zombie {
 public:
  Zombie(void); 
  ~Zombie(void);
  void announce(void);
  void setName(std::string const& name);
  std::string const& getName(void) const;

 private:
  std::string _name;
};


Zombie* zombieHorde(int N, std::string name);


#endif // ZOMBIE_H

