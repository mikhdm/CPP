/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 21:03:32 by rmander           #+#    #+#             */
/*   Updated: 2022/01/06 18:07:13 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

#include "Animal.hpp"


WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
  WrongAnimal::log("WrongCat constructor", SH_COLOR_GREEN);
}


WrongCat::WrongCat(WrongCat const& instance) : WrongAnimal("WrongCat") {
  if (this == &instance)
    return ;
  *this = instance;
  WrongAnimal::log("WrongCat copy constructor", SH_COLOR_GREEN);
}


WrongCat::~WrongCat(void) {
  WrongAnimal::log("WrongCat destructor", SH_COLOR_GREEN);
}


WrongCat& WrongCat::operator=(WrongCat const& instance) {
  if (this == &instance)
    return *this;
  type = instance.getType();
  return *this;
}

void WrongCat::makeSound(void) const {
  WrongAnimal::log("WrongCat Meow!", SH_COLOR_GREEN);
}

