/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:31:37 by rmander           #+#    #+#             */
/*   Updated: 2022/01/06 18:06:48 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"


Dog::Dog(void) : Animal("Dog") {
  Animal::log("Dog constructor", SH_COLOR_YELLOW);
}


Dog::Dog(Dog const& instance) : Animal("Dog") {
  if (this == &instance)
    return ;
  *this = instance;
  Animal::log("Dog copy constructor", SH_COLOR_YELLOW);
}


Dog::~Dog(void) {
  Animal::log("Dog destructor", SH_COLOR_YELLOW);
}


Dog& Dog::operator=(Dog const& instance) {
  if (this == &instance)
    return *this;
  type = instance.getType();
  return *this;
}


void Dog::makeSound(void) const {
  Animal::log("Bark!", SH_COLOR_YELLOW);
}
