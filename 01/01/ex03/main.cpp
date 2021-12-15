/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:24:57 by rmander           #+#    #+#             */
/*   Updated: 2021/12/15 18:20:14 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

#include <cstdlib>


int main(void) {

   {
      Weapon club = Weapon("crude spiked club");
      HumanA bob("Bob", club);
      bob.attack();
      club.setType("some other type of club");
      bob.attack();
   }
   {
      Weapon club = Weapon("crude spiked club");
      HumanB jim("Jim");
      jim.setWeapon(club);
      jim.attack();
      club.setType("some other type of club");
      jim.attack();
   }

   return (EXIT_SUCCESS);
}

