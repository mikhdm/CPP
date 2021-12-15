/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:29:58 by rmander           #+#    #+#             */
/*   Updated: 2021/12/15 18:23:11 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

#include <iostream>


HumanB::HumanB(std::string const& name) : _name(name),
                                          _weapon(nullptr) {}


HumanB::~HumanB(void) {}


void HumanB::attack(void) const {
   if (_weapon)
      std::cout<<_name<<" attacks with his "<<_weapon->getType()<<std::endl;
}


void HumanB::setWeapon(Weapon const& weapon) {
   _weapon = &weapon;
}


Weapon const* HumanB::getWeapon(void) const {
   return _weapon;
}
