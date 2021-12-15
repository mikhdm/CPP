/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:40:51 by rmander           #+#    #+#             */
/*   Updated: 2021/12/15 14:38:03 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <iostream>


Zombie::Zombie(void) {}


Zombie::~Zombie(void) {
  std::cout<<SH_COLOR_RED<<_name<<" "<<"has been destroyed"
    <<SH_COLOR_RESET<<std::endl;
}


void Zombie::setName(std::string const& name) {
  _name = name;
}


void Zombie::announce(void) {
  std::cout<<_name<<" "<<"BraiiiiiiinnnzzzZ..."<<std::endl;
}

