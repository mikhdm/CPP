/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:12:28 by rmander           #+#    #+#             */
/*   Updated: 2021/12/22 17:13:29 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#include <iostream>

const unsigned int FragTrap::_kHitPointsMax = 100;
const unsigned int FragTrap::_kAttackDamage = 30; 


FragTrap::FragTrap(std::string const& name) : ClapTrap(name) {
  _hitPointsMax = FragTrap::_kHitPointsMax;
  _hitPoints = FragTrap::_kHitPointsMax;
  _energy = 100;
  _attackDamage = FragTrap::_kAttackDamage;
  std::cout << SH_COLOR_BLUE << "FR4G-TP: " << _name
    << " has been created" << SH_COLOR_RESET << std::endl;
}


FragTrap::FragTrap(FragTrap const& instance) : ClapTrap(instance.getName()) {
  if (this == &instance)
    return ;
  *this = instance;
  std::cout << SH_COLOR_BLUE << "FR4G-TP: " << _name 
    << " copy has been created" << SH_COLOR_RESET << std::endl;
}


FragTrap& FragTrap::operator=(FragTrap const& instance) {
  if (this == &instance)
    return *this;
  _name = instance.getName();
  _hitPoints = instance.getHitPoints();
  _hitPointsMax = instance.getHitPointsMax();
  _energy = instance.getEnergy();
  _attackDamage = instance.getAttackDamage();

  std::cout << SH_COLOR_BLUE << "FR4G-TP: " << _name
    << " has been assigned" << SH_COLOR_RESET << std::endl;
  return *this;
}


FragTrap::~FragTrap(void) {
  std::cout << SH_COLOR_BLUE << "FR4G-TP: " << _name
    << " has been destroyed" << SH_COLOR_RESET << std::endl;
}


void FragTrap::attack(std::string const& target) {
  if (_hitPoints == 0) {
    std::cerr << "FR4G-TP: " << _name << " is dead (HP = 0)" << std::endl; 
    return ;
  }
  if (_energy == 0) {
    std::cerr << "FR4G-TP: " << _name << ": "
      << "Try again later (Energy = 0)" << std::endl;
    return ;
  }
  std::cout << SH_COLOR_BLUE
    << "FR4G-TP: " << _name << " attacks " << target << ", "
    << "causing " << _name <<" points of damage (OOUUCHHHHH!)"
    SH_COLOR_RESET << std::endl;
  --_energy;
}


void FragTrap::highFivesGuys(void) {
  std::cout << SH_COLOR_BLUE
    << "FR4G-TP: " << _name << " asks: " << "Gimme FIIIIVE!"
    SH_COLOR_RESET << std::endl;
}

