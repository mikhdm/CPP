/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:56:26 by rmander           #+#    #+#             */
/*   Updated: 2022/01/05 20:23:57 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"


Cat::Cat(void) : Animal() {
  setType("Cat");
  Cat::log(type + " created", SH_COLOR_GREEN);
}


Cat::Cat(Cat const& instance) {
  if (this == &instance)
    return ;
  *this = instance;
  Cat::log(type + " copy created", SH_COLOR_GREEN);
}


Cat::~Cat(void) {
  Cat::log(type + " destroyed", SH_COLOR_GREEN);
}


Cat& Cat::operator=(Cat const& instance) {
  if (this == &instance)
    return *this;
  type = instance.getType();
  return *this;
}
