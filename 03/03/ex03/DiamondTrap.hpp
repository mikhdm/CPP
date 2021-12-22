/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:41:01 by rmander           #+#    #+#             */
/*   Updated: 2021/12/22 16:47:20 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

# include "ScavTrap.hpp"
# include "FragTrap.hpp"


class DiamondTrap : public ScavTrap, public FragTrap {
 public:
  DiamondTrap(std::string const& name);
  DiamondTrap(DiamondTrap const& instance);
  virtual ~DiamondTrap(void);
  DiamondTrap& operator=(DiamondTrap const& instance);

  void WhoAmI(void);
  using ScavTrap::attack;

 private:
  DiamondTrap(void);
  std::string _name;
};

#endif
