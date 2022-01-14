/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:31:37 by rmander           #+#    #+#             */
/*   Updated: 2022/01/14 23:14:15 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include "Animal.hpp"


Dog::Dog(void) : Animal("Dog"), brain(new Brain()) {
  Animal::log("Dog constructor", SH_COLOR_YELLOW);
}


Dog::~Dog(void) {
  delete brain;
  Animal::log("Dog destructor", SH_COLOR_YELLOW);
}


Dog::Dog(Dog const& instance) : Animal("Dog"), brain(new Brain()) {
  if (this == &instance)
    return ;
  *this = instance;
  Animal::log("Dog copy constructor", SH_COLOR_YELLOW);
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
  Animal::log("Bark!", SH_COLOR_YELLOW);
}
