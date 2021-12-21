/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 22:43:39 by rmander           #+#    #+#             */
/*   Updated: 2021/12/22 02:05:15 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
 public:
  ScavTrap(std::string const& name);
  ScavTrap(ScavTrap const& instance);
  virtual ~ScavTrap(void);
  ScavTrap& operator=(ScavTrap const& instance);

  void guardGate(void);

 private:
  ScavTrap(void);
};

#endif // SCAVTRAP_H
