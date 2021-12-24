/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 20:09:28 by rmander           #+#    #+#             */
/*   Updated: 2021/12/25 00:41:19 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include <iostream>


int main(void) {

  ClapTrap o("Orion");
  ClapTrap s("Sequoia");
  std::cout << std::endl;

  o.attack(s.getName());
  s.takeDamage(o.getAttackDamage());

  s.attack(o.getName());
  o.takeDamage(s.getAttackDamage());

  for (size_t i = 0; i < 10; ++i) {
    if (s.getEnergy())
    {
      s.attack(o.getName());
      o.takeDamage(s.getAttackDamage());
    }
  }
  
  // Insufficient energy
  s.attack(o.getName());

  o.beRepaired(100);
  s.beRepaired(100);

  ClapTrap scopy(s);
  scopy = o;

  return (EXIT_SUCCESS);
}

