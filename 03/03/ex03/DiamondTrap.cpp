/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:40:59 by rmander           #+#    #+#             */
/*   Updated: 2021/12/22 17:31:09 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#include <iostream>


DiamondTrap::DiamondTrap(std::string const& name) : ClapTrap(name + "__clap__name"),
                                                    ScavTrap(name + "__clap__name"),
                                                    FragTrap(name + "__clap__name"),
                                                    _name(name) {
  _hitPointsMax = FragTrap::_kHitPointsMax;
  _hitPoints = _hitPointsMax;
  _energy = ScavTrap::_kEnergy;
  _attackDamage = FragTrap::_kAttackDamage;
  std::cout << SH_COLOR_YELLOW << "DI4MOND-TP: " << _name
    << " has been created" << SH_COLOR_RESET << std::endl;
}


DiamondTrap::DiamondTrap(DiamondTrap const& instance) : ClapTrap(instance.getName() + "__clap__name"),
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
  _hitPointsMax = instance.getHitPointsMax();
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


std::string const& DiamondTrap::getName(void) const {
  return _name;
}


void DiamondTrap::WhoAmI(void) {
  std::cout << SH_COLOR_YELLOW << 
    "DI4MOND-TP: " << _name << ": " << ClapTrap::_name << " I am!" 
    << SH_COLOR_RESET << std::endl;
}
