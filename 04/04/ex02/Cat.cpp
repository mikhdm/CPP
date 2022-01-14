/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:56:26 by rmander           #+#    #+#             */
/*   Updated: 2022/01/14 23:14:13 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include "AAnimal.hpp"


Cat::Cat(void) : AAnimal("Cat"), brain(new Brain()) {
  AAnimal::log("Cat constructor", SH_COLOR_GREEN);
}


Cat::~Cat(void) {
  delete brain;
  AAnimal::log("Cat destructor", SH_COLOR_GREEN);
}


Cat::Cat(Cat const& instance) : AAnimal("Cat"), brain(new Brain()) {
  if (this == &instance)
    return ;
  *this = instance;
  AAnimal::log("Cat copy constructor", SH_COLOR_GREEN);
}


Cat& Cat::operator=(Cat const& instance) {
  if (this == &instance)
    return *this;
  type = instance.getType();
  Brain const* brain_from = instance.getBrain();
  *brain  = *brain_from;
  return *this;
}


Brain* Cat::getBrain(void) const {
  return brain;
}


void Cat::makeSound(void) const {
  AAnimal::log("Meow!", SH_COLOR_GREEN);
}
