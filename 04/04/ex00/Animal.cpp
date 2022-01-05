/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 23:27:58 by rmander           #+#    #+#             */
/*   Updated: 2022/01/06 00:01:47 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#include <iostream>
#include <string>


void Animal::log(std::string const& message, std::string const& color) {
  std::cout << color << message << SH_COLOR_RESET << std::endl;
}


Animal::Animal(void) : type("Animal") {
  Animal::log("Animal constructor", SH_COLOR_WHITE);
}


Animal::Animal(std::string const& ty) : type(ty) {
  Animal::log("Animal constructor", SH_COLOR_WHITE);
}


Animal::Animal(Animal const& instance) {
  if (this == &instance)
    return ;
  *this = instance;
  Animal::log("Animal copy constructor", SH_COLOR_WHITE);
}


Animal::~Animal(void) {
  Animal::log("Animal destructor", SH_COLOR_WHITE);
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
  Animal::log("Animal sound here!", SH_COLOR_WHITE);
}

