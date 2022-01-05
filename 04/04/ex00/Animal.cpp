/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 23:27:58 by rmander           #+#    #+#             */
/*   Updated: 2022/01/05 20:38:22 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#include <iostream>
#include <string>


void Animal::log(std::string const& message, std::string const& color) {
  std::cout << color << message << SH_COLOR_RESET << std::endl;
}


Animal::Animal(void) : type("Animal") {
  Animal::log(type + " created", SH_COLOR_WHITE);
}


Animal::Animal(Animal const& instance) {
  if (this == &instance)
    return ;
  *this = instance;
  Animal::log(type + " copy created", SH_COLOR_WHITE);
}


Animal::~Animal(void) {
  Animal::log(type + " destroyed", SH_COLOR_WHITE);
}


Animal& Animal::operator=(Animal const& instance) {
  if (this == &instance)
    return *this;
  type = instance.getType();
  return *this;
}


std::string const& Animal::getType(void) const {
  return type;
}


void Animal::setType(std::string const& newType) {
  type = newType;
}


void Animal::makeSound(void) const {
  Animal::log("I'm " + type + "!", SH_COLOR_WHITE);
}

