/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:24:06 by rmander           #+#    #+#             */
/*   Updated: 2021/12/25 00:40:49 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include <iostream>


ClapTrap::ClapTrap(std::string const& name) : _name(name),
                                              _hitPoints(10),
                                              _energy(10),
                                              _attackDamage(0),
                                              _kHitPointsMax(10) {
  std::cout << SH_COLOR_GREEN << "CL4P-TP: " << _name
    << " has been created" << SH_COLOR_RESET << std::endl;
}


ClapTrap::ClapTrap(ClapTrap const& instance) : _kHitPointsMax(10) {
  if (this == &instance)
    return ;
  *this = instance;
  std::cout << SH_COLOR_GREEN << "CL4P-TP: " << _name
    << " copy has been created" << SH_COLOR_RESET << std::endl;
}


ClapTrap& ClapTrap::operator=(ClapTrap const& instance) {
  if (this == &instance)
    return *this;
  _name = instance.getName();
  _hitPoints = instance.getHitPoints();
  _energy = instance.getEnergy();
  _attackDamage = instance.getAttackDamage();

  std::cout << SH_COLOR_GREEN << "CL4P-TP: " << _name
    << " has been assigned" << SH_COLOR_RESET << std::endl;
  return *this;
}


ClapTrap::~ClapTrap(void) {
  std::cout << SH_COLOR_GREEN << "CL4P-TP: " << _name
    << " has been destroyed" << SH_COLOR_RESET << std::endl;
}


std::string const& ClapTrap::getName(void) const {
  return _name;
}


unsigned int ClapTrap::getHitPoints(void) const {
  return _hitPoints;
}


unsigned int ClapTrap::getEnergy(void) const {
  return _energy;
}


unsigned int ClapTrap::getAttackDamage(void) const {
  return _attackDamage;
} 


void ClapTrap::attack(std::string const& target) {
  if (_hitPoints == 0) {
    std::cerr << "CL4P-TP: " << _name << " is dead (HP = 0)" << std::endl; 
    return ;
  }
  if (_energy == 0) {
    std::cerr << "CL4P-TP: " << _name << ": "
      << "Try again later (Energy = 0)" << std::endl;
    return ;
  }
  std::cout << SH_COLOR_GREEN
    << "CL4P-TP: " << _name << " attacks " << target << ", "
    << "causing " << _attackDamage <<" points of damage"
    SH_COLOR_RESET << std::endl;
  --_energy;
}


void ClapTrap::takeDamage(unsigned int amount) {
  unsigned int prev = _hitPoints;

  if (_hitPoints == 0) {
    std::cerr << "CL4P-TP: " << _name << " is dead (HP = 0)" << std::endl;
    return ;
  }
  _hitPoints = (amount >= _hitPoints) ? 0 : _hitPoints - amount;
  std::cout << SH_COLOR_GREEN
    << "CL4P-TP: " << _name
    << " losts " << prev - _hitPoints << " points"
    << SH_COLOR_RESET << std::endl; 
}


void ClapTrap::beRepaired(unsigned int amount) {
  unsigned int prev = _hitPoints;

  if (_hitPoints == _kHitPointsMax) {
    std::cerr << "CL4P-TP: " << _name << " is repaired enough" << std::endl;
    return ;
  }
  unsigned long tmp = static_cast<unsigned long>(_hitPoints) + static_cast<unsigned long>(amount);
  _hitPoints = ( tmp > static_cast<unsigned long>(_kHitPointsMax) ) ? _kHitPointsMax : _hitPoints + amount;
  std::cout << SH_COLOR_GREEN << "CL4P-TP: " << _name << " was healed by "
    << _hitPoints - prev
    << SH_COLOR_RESET << std::endl;
}
