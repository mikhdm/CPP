/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:31:37 by rmander           #+#    #+#             */
/*   Updated: 2022/01/14 23:14:12 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include "AAnimal.hpp"


Dog::Dog(void) : AAnimal("Dog"), brain(new Brain()) {
  AAnimal::log("Dog constructor", SH_COLOR_YELLOW);
}


Dog::~Dog(void) {
  delete brain;
  AAnimal::log("Dog destructor", SH_COLOR_YELLOW);
}


Dog::Dog(Dog const& instance) : AAnimal("Dog"), brain(new Brain()) {
  if (this == &instance)
    return ;
  *this = instance;
  AAnimal::log("Dog copy constructor", SH_COLOR_YELLOW);
}


Dog& Dog::operator=(Dog const& instance) {
  if (this == &instance)
    return *this;
  type = instance.getType();
  Brain const* brain_from = instance.getBrain();
  *brain  = *brain_from;
  return *this;
}


Brain* Dog::getBrain(void) const {
  return brain;
}


void Dog::makeSound(void) const {
  AAnimal::log("Bark!", SH_COLOR_YELLOW);
}
