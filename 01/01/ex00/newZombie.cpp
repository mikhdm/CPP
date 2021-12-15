/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:33:13 by rmander           #+#    #+#             */
/*   Updated: 2021/12/15 15:27:13 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


Zombie *newZombie(std::string name) {
  if (name.empty())
    return nullptr;
  Zombie *z = new Zombie;
  z->setName(name);
  return z;
}

