/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 00:27:51 by rmander           #+#    #+#             */
/*   Updated: 2021/12/22 16:50:51 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#include <iostream>

#include "ClapTrap.hpp"


ScavTrap::ScavTrap(std::string const& name) : ClapTrap(name) {
  _hitPointsMax = 100;
  _hitPoints = _hitPointsMax;
  _energy = 50;
  _attackDamage = 20;
  std::cout << SH_COLOR_PURPLE << "SC4V-TP: " << _name 
    << " has been created" << SH_COLOR_RESET << std::endl;
}


ScavTrap::ScavTrap(ScavTrap const& instance) : ClapTrap(instance.getName()) {
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
  _hitPointsMax = instance.getHitPointsMax();
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


void ScavTrap::attack(std::string const& target) {
  if (_hitPoints == 0) {
    std::cerr << "SC4V-TP: " << _name << " is dead (HP = 0)" << std::endl; 
    return ;
  }
  if (_energy == 0) {
    std::cerr << "SC4V-TP: " << _name << ": "
      << "Try again later (Energy = 0)" << std::endl;
    return ;
  }
  std::cout << SH_COLOR_PURPLE
    << "SC4V-TP: " << _name << " attacks " << target << ", "
    << "causing " << _attackDamage <<" points of damage (AAASHH!)"
    SH_COLOR_RESET << std::endl;
  --_energy;
}


void ScavTrap::guardGate(void) {
  std::cout << SH_COLOR_PURPLE << "SC4V-TP: " << _name
    << " has entered Gate keeper mode" << SH_COLOR_RESET << std::endl;
}

