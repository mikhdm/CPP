/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:56:26 by rmander           #+#    #+#             */
/*   Updated: 2022/01/06 18:06:34 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"


Cat::Cat(void) : Animal("Cat") {
  Animal::log("Cat constructor", SH_COLOR_GREEN);
}


Cat::Cat(Cat const& instance) : Animal("Cat") {
  if (this == &instance)
    return ;
  *this = instance;
  Animal::log("Cat copy constructor", SH_COLOR_GREEN);
}


Cat::~Cat(void) {
  Animal::log("Cat destructor", SH_COLOR_GREEN);
}


Cat& Cat::operator=(Cat const& instance) {
  if (this == &instance)
    return *this;
  type = instance.getType();
  return *this;
}

void Cat::makeSound(void) const {
  Animal::log("Meow!", SH_COLOR_GREEN);
}
