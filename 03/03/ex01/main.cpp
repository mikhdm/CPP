/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 20:09:28 by rmander           #+#    #+#             */
/*   Updated: 2021/12/25 00:46:51 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"


int main(void) {
  ScavTrap g("Garbion");
  ScavTrap b("Broniboy");

  std::cout << std::endl;

  g.attack(b.getName());
  b.takeDamage(g.getAttackDamage());

  g.attack(b.getName());
  b.takeDamage(g.getAttackDamage());

  g.attack(b.getName());
  b.takeDamage(g.getAttackDamage());

  std::cout << std::endl;

  std::cout << g.getName() << " has " << g.getHitPoints() << " HP" << std::endl; 
  std::cout << b.getName() << " has " << b.getHitPoints() << " HP" << std::endl; 

  std::cout << std::endl;

  b.attack(g.getName());
  g.takeDamage(b.getAttackDamage());

  std::cout << std::endl;

  std::cout << g.getName() << " has " << g.getHitPoints() << " HP" << std::endl; 
  std::cout << b.getName() << " has " << b.getHitPoints() << " HP" << std::endl; 

  std::cout << std::endl;
  
  // Create copy via copy constructor
  ScavTrap gcopy(g);

  std::cout << gcopy.getName() << " (copy)" << " has "
    << gcopy.getHitPoints() << " HP, "
    << gcopy.getEnergy() << " Energy, "
    << gcopy.getAttackDamage() << " Attack damage" << std::endl;


  std::cout << std::endl;

  ScavTrap a("Ariadna");

  std::cout << std::endl;

  a.attack(b.getName());
  b.takeDamage(a.getAttackDamage());

  b.attack(a.getName());
  a.takeDamage(b.getAttackDamage());
  
  std::cout << std::endl;

  std::cout << a.getName() << " has "
    << a.getHitPoints() << " HP, "
    << a.getEnergy() << " Energy, "
    << a.getAttackDamage() << " Attack damage" << std::endl;

  std::cout << std::endl;
  
  // Reassign Garbion copy with new data from Ariadna (already a little damaged)
  gcopy = a;
  std::cout << gcopy.getName() << " (" << g.getName() + " copy before)" << " has "
    << gcopy.getHitPoints() << " HP " << std::endl;

  std::cout << std::endl;

  return (EXIT_SUCCESS);
}

