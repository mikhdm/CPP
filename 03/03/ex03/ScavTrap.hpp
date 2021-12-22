/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 22:43:39 by rmander           #+#    #+#             */
/*   Updated: 2021/12/22 17:15:15 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "ClapTrap.hpp"


class ScavTrap : public virtual ClapTrap {
 public:
  ScavTrap(std::string const& name);
  ScavTrap(ScavTrap const& instance);
  virtual ~ScavTrap(void);
  ScavTrap& operator=(ScavTrap const& instance);

  void attack(std::string const& target);
  void guardGate(void);

 protected:
  static unsigned int const _kEnergy;

 private:
  ScavTrap(void);
};

#endif // SCAVTRAP_H
