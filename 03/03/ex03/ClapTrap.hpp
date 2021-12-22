/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:24:11 by rmander           #+#    #+#             */
/*   Updated: 2021/12/22 17:30:00 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <string>

# define SH_COLOR_WHITE		"\033[37m"
# define SH_COLOR_BLUE		"\033[34m"
# define SH_COLOR_PURPLE	"\033[35m"
# define SH_COLOR_RED			"\033[31m"
# define SH_COLOR_YELLOW	"\033[33m"
# define SH_COLOR_GREEN		"\033[32m"
# define SH_COLOR_RESET		"\033[m"
# define SH_COLOR_BOLD		"\033[1m"


class ClapTrap {
 public:
  ClapTrap(std::string const& name);
  ClapTrap(ClapTrap const& instance);
  virtual ~ClapTrap(void);
  ClapTrap& operator=(ClapTrap const& instance);

  std::string const& getName(void) const;
  unsigned int getHitPoints(void) const;
  unsigned int getHitPointsMax(void) const;
  unsigned int getEnergy(void) const;
  unsigned int getAttackDamage(void) const;

  void attack(std::string const& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

 protected:
  std::string _name;
  unsigned int _hitPoints;
  unsigned int _energy;
  unsigned int _attackDamage;
  unsigned int _hitPointsMax;

 private:
  ClapTrap(void);
};


#endif // CLAPTRAP_H

