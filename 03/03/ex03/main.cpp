/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 20:09:28 by rmander           #+#    #+#             */
/*   Updated: 2021/12/22 16:39:35 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "DiamondTrap.hpp"

#include <iostream>


void div(void) {
  std::cout << std::endl;
}

void info(ClapTrap const& instance) {
  std::cout << instance.getName() << " has "
    << instance.getHitPoints() << " HP, "
    << instance.getEnergy() << " Energy, "
    << instance.getAttackDamage() << " Attack damage" << std::endl;
}


int main(void) {
  DiamondTrap dia_d("Bellatrix");
  DiamondTrap dia_s("Sirius");
  ScavTrap scav_a("Ariadna");

  div();
  
  info(dia_d);
  info(scav_a);

  div();

  dia_d.attack(dia_s.getName());
  dia_s.takeDamage(dia_s.getAttackDamage());

  div();

  dia_d.WhoAmI();

  div();

  return (EXIT_SUCCESS);
}

