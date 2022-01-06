/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:56:26 by rmander           #+#    #+#             */
/*   Updated: 2022/01/06 19:32:48 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include "AAnimal.hpp"


Cat::Cat(void) : AAnimal("Cat") {
  AAnimal::log("Cat constructor", SH_COLOR_GREEN);
}


Cat::Cat(Cat const& instance) : AAnimal("Cat") {
  if (this == &instance)
    return ;
  *this = instance;
  AAnimal::log("Cat copy constructor", SH_COLOR_GREEN);
}


Cat::~Cat(void) {
  AAnimal::log("Cat destructor", SH_COLOR_GREEN);
}


Cat& Cat::operator=(Cat const& instance) {
  if (this == &instance)
    return *this;
  type = instance.getType();
  return *this;
}

void Cat::makeSound(void) const {
  AAnimal::log("Meow!", SH_COLOR_GREEN);
}
