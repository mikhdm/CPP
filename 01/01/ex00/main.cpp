/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:38:05 by rmander           #+#    #+#             */
/*   Updated: 2021/12/15 14:55:14 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <cstdlib>


int main(void) {
  Zombie *z = newZombie("A-Virus");
  randomChump("C-Virus");
  delete z;
  return (EXIT_SUCCESS);
}

