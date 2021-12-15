/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:24:02 by rmander           #+#    #+#             */
/*   Updated: 2021/12/15 15:39:19 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <iostream>


int main(void) {
  const int N = 10;
  Zombie *zs = zombieHorde(N, "A-Virus");
  if (!zs)
    return (EXIT_FAILURE);

  for (int i = 0; i < N; ++i) {
    zs[i].announce();
  }
  delete [] zs;
  return (EXIT_SUCCESS);
}
