/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:31:37 by rmander           #+#    #+#             */
/*   Updated: 2022/01/05 20:31:52 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"


Dog::Dog(void) : Animal() {
  setType("Dog");
  Dog::log(type + " created", SH_COLOR_GREEN);
}


Dog::Dog(Dog const& instance) {
  if (this == &instance)
    return ;
  *this = instance;
  Dog::log(type + " copy created", SH_COLOR_GREEN);
}


Dog::~Dog(void) {
  Dog::log(type + " destroyed", SH_COLOR_GREEN);
}


Dog& Dog::operator=(Dog const& instance) {
  if (this == &instance)
    return *this;
  type = instance.getType();
  return *this;
}
