/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:31:37 by rmander           #+#    #+#             */
/*   Updated: 2022/01/06 19:33:45 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include "AAnimal.hpp"


Dog::Dog(void) : AAnimal("Dog") {
  AAnimal::log("Dog constructor", SH_COLOR_YELLOW);
}


Dog::Dog(Dog const& instance) : AAnimal("Dog") {
  if (this == &instance)
    return ;
  *this = instance;
  AAnimal::log("Dog copy constructor", SH_COLOR_YELLOW);
}


Dog::~Dog(void) {
  AAnimal::log("Dog destructor", SH_COLOR_YELLOW);
}


Dog& Dog::operator=(Dog const& instance) {
  if (this == &instance)
    return *this;
  type = instance.getType();
  return *this;
}


void Dog::makeSound(void) const {
  AAnimal::log("Bark!", SH_COLOR_YELLOW);
}
