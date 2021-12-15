/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:28:19 by rmander           #+#    #+#             */
/*   Updated: 2021/12/15 15:39:17 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


Zombie* zombieHorde(int N, std::string name) {
  if (N <= 0)
    return nullptr;
  if (name.empty())
    return nullptr;
  Zombie *zs = new Zombie[N];
  for (int i = 0; i < N; ++i) {
    zs[i].setName(name);
  }
  return (zs);
}

