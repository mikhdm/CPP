/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 20:09:28 by rmander           #+#    #+#             */
/*   Updated: 2021/12/22 12:36:12 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

void div(void) {
  std::cout << std::endl;
}


int main(void) {
  ScavTrap g("Garbion");
  ScavTrap b("Broniboy");

  div();

  g.attack(b.getName());
  b.takeDamage(g.getAttackDamage());

  g.attack(b.getName());
  b.takeDamage(g.getAttackDamage());

  g.attack(b.getName());
  b.takeDamage(g.getAttackDamage());

  div();

  std::cout << g.getName() << " has " << g.getHitPoints() << " HP" << std::endl; 
  std::cout << b.getName() << " has " << b.getHitPoints() << " HP" << std::endl; 

  div();

  b.attack(g.getName());
  g.takeDamage(b.getAttackDamage());

  div();

  std::cout << g.getName() << " has " << g.getHitPoints() << " HP" << std::endl; 
  std::cout << b.getName() << " has " << b.getHitPoints() << " HP" << std::endl; 

  div();
  
  // Create copy via copy constructor
  ScavTrap gcopy(g);

  std::cout << gcopy.getName() << " (copy)" << " has "
    << gcopy.getHitPoints() << " HP, "
    << gcopy.getEnergy() << " Energy, "
    << gcopy.getAttackDamage() << " Attack damage" << std::endl;


  div();

  ScavTrap a("Ariadna");

  div();

  a.attack(b.getName());
  b.takeDamage(a.getAttackDamage());

  b.attack(a.getName());
  a.takeDamage(b.getAttackDamage());
  
  div();

  std::cout << a.getName() << " has "
    << a.getHitPoints() << " HP, "
    << a.getEnergy() << " Energy, "
    << a.getAttackDamage() << " Attack damage" << std::endl;

  div();
  
  // Reassign Garbion copy with new data from Ariadna (already a little damaged)
  gcopy = a;
  std::cout << gcopy.getName() << " (" << g.getName() + " copy before)" << " has "
    << gcopy.getHitPoints() << " HP " << std::endl;

  a.guardGate();

  div();

  FragTrap ar("Moulinette");
  FragTrap ex("Terminator"); 

  div();

  ar.highFivesGuys();
  ex.highFivesGuys();

  div();

  ar.attack(ex.getName());
  ex.takeDamage(ar.getAttackDamage());

  std::cout << ar.getName() << " has "
    << ar.getHitPoints() << " HP, "
    << ar.getEnergy() << " Energy, "
    << ar.getAttackDamage() << " Attack damage" << std::endl;

  return (EXIT_SUCCESS);
}

