/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 00:27:51 by rmander           #+#    #+#             */
/*   Updated: 2021/12/22 02:25:33 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#include <iostream>

#include "ClapTrap.hpp"


ScavTrap::ScavTrap(std::string const& name) : ClapTrap(name, 100, 50, 20) {
  std::cout << SH_COLOR_PURPLE << "SC4V-TP: " << _name
    << " has been created" << SH_COLOR_RESET << std::endl;
}


ScavTrap::ScavTrap(ScavTrap const& instance) : ClapTrap(100) {
  if (this == &instance)
    return ;
  *this = instance;
  std::cout << SH_COLOR_PURPLE << "SC4V-TP: " << _name
    << " copy has been created" << SH_COLOR_RESET << std::endl;
}


ScavTrap& ScavTrap::operator=(ScavTrap const& instance) {
  if (this == &instance)
    return *this;
  _name = instance.getName();
  _hitPoints = instance.getHitPoints();
  _energy = instance.getEnergy();
  _attackDamage = instance.getAttackDamage();

  std::cout << SH_COLOR_PURPLE << "SC4V-TP: " << _name
    << " has been assigned" << SH_COLOR_RESET << std::endl;

  return *this;
}


ScavTrap::~ScavTrap(void) {
  std::cout << SH_COLOR_PURPLE << "SC4V-TP: " << _name
    << " has been destroyed" << SH_COLOR_RESET << std::endl;
}


void ScavTrap::guardGate(void) {
  std::cout << SH_COLOR_PURPLE << "SC4V-TP: " << _name
    << " has entered Gate keeper mode" << SH_COLOR_RESET << std::endl;
}
