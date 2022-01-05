/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 21:00:00 by rmander           #+#    #+#             */
/*   Updated: 2022/01/06 00:20:52 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongAnimal.hpp"

# include <iostream>
# include <string>

# include "Animal.hpp"


void WrongAnimal::log(std::string const& message, std::string const& color) {
  std::cout << color << message << SH_COLOR_RESET << std::endl;
}


WrongAnimal::WrongAnimal(void) : type("WrongAnimal") {
  WrongAnimal::log("WrongAnimal constructor", SH_COLOR_WHITE);
}


WrongAnimal::WrongAnimal(std::string const& ty) : type(ty) {
  WrongAnimal::log("WrongAnimal constructor", SH_COLOR_WHITE);
}


WrongAnimal::WrongAnimal(WrongAnimal const& instance) {
  if (this == &instance)
    return ;
  *this = instance;
  WrongAnimal::log("WrongAnimal copy constructor", SH_COLOR_WHITE);
}


WrongAnimal::~WrongAnimal(void) {
  WrongAnimal::log("WrongAnimal destructor", SH_COLOR_WHITE);
}


WrongAnimal& WrongAnimal::operator=(WrongAnimal const& instance) {
  if (this == &instance)
    return *this;
  type = instance.getType();
  return *this;
}


std::string const& WrongAnimal::getType(void) const {
  return type;
}


void WrongAnimal::setType(std::string const& newType) {
  type = newType;
}


void WrongAnimal::makeSound(void) const {
  WrongAnimal::log("WrongAnimal sound here!", SH_COLOR_RED);
}

