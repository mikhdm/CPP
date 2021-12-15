/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:15:09 by rmander           #+#    #+#             */
/*   Updated: 2021/12/15 18:25:47 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

#include <iostream>
#include <string>

#include "Weapon.hpp"


HumanA::HumanA(std::string const& name, Weapon const& weapon) : _name(name),
                                                                _weapon(weapon) {}


HumanA::~HumanA() {}


void HumanA::attack(void) const {
   std::cout<<_name<<" attacks with his "<<_weapon.getType()<<std::endl;
}

