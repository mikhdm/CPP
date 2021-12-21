/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 20:09:28 by rmander           #+#    #+#             */
/*   Updated: 2021/12/22 02:36:15 by rmander          ###   ########.fr       */
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

  ScavTrap gcopy(g);

  std::cout << std::endl;

  ScavTrap a("Ariadna");

  std::cout << std::endl;

  a.attack(b.getName());
  b.takeDamage(a.getAttackDamage());

  b.attack(a.getName());
  a.takeDamage(b.getAttackDamage());
  
  std::cout << std::endl;

  std::cout << a.getName()  << " has "
    << a.getHitPoints() << " HP " << std::endl;

  std::cout << std::endl;

  gcopy = a;
  std::cout << gcopy.getName() << " (" << g.getName() + " copy before)" << " has "
    << gcopy.getHitPoints() << " HP " << std::endl;

  std::cout << std::endl;

  return (EXIT_SUCCESS);
}

