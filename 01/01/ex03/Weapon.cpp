/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:02:45 by rmander           #+#    #+#             */
/*   Updated: 2021/12/15 18:20:12 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

#include <string>


Weapon::Weapon(void) {}


Weapon::Weapon(std::string const& ty) : type(ty) {}


Weapon::~Weapon(void) {}



std::string const& Weapon::getType(void) const {
   return type;
}


void Weapon::setType(std::string const& ty) {
   type = ty;
}

