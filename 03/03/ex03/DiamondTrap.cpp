/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:40:59 by rmander           #+#    #+#             */
/*   Updated: 2021/12/22 15:52:31 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#include <iostream>


DiamondTrap::DiamondTrap(std::string const& name) : 
                                                    ClapTrap(name + "__clap__name", 100),
                                                    ScavTrap(name + "__clap__name"),
                                                    FragTrap(name + "__clap__name"),
                                                    _name(name) {
  std::cout << SH_COLOR_YELLOW << "DI4MOND-TP: " << _name
    << " has been created" << SH_COLOR_RESET << std::endl;
}


DiamondTrap::DiamondTrap(DiamondTrap const& instance) : ClapTrap(instance.getName() + "__clap__name", 100),
                                                        ScavTrap(instance.getName() + "__clap__name"),
                                                        FragTrap(instance.getName() + "__clap__name") {
    if (this == &instance)
        return ;
    *this = instance;
  std::cout << SH_COLOR_YELLOW << "DI4MOND-TP: " << _name
    << " copy has been created" << SH_COLOR_RESET << std::endl;
}


DiamondTrap& DiamondTrap::operator=(DiamondTrap const& instance) {
  if (this == &instance)
    return *this;
  _name = instance.getName();
  _hitPoints = instance.getHitPoints();
  _energy = instance.getEnergy();
  _attackDamage = instance.getAttackDamage();

  std::cout << SH_COLOR_YELLOW << "DI4MOND-TP: " << _name
    << " has been assigned" << SH_COLOR_RESET << std::endl;
  return *this;
}


DiamondTrap::~DiamondTrap(void) {
  std::cout << SH_COLOR_YELLOW << "DI4MOND-TP: " << _name
    << " has been destroyed" << SH_COLOR_RESET << std::endl;
}


void DiamondTrap::WhoAmI(void) {

}
