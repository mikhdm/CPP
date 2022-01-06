/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 23:27:58 by rmander           #+#    #+#             */
/*   Updated: 2022/01/06 19:36:59 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

#include <iostream>
#include <string>


void AAnimal::log(std::string const& message, std::string const& color) {
  std::cout << color << message << SH_COLOR_RESET << std::endl;
}


AAnimal::AAnimal(void) {
  AAnimal::log("AAnimal constructor", SH_COLOR_WHITE);
}


AAnimal::AAnimal(std::string const& ty) : type(ty) {
  AAnimal::log("AAnimal constructor", SH_COLOR_WHITE);
}


AAnimal::AAnimal(AAnimal const& instance) {
  if (this == &instance)
    return ;
  *this = instance;
  AAnimal::log("AAnimal copy constructor", SH_COLOR_WHITE);
}


AAnimal::~AAnimal(void) {
  AAnimal::log("AAnimal destructor", SH_COLOR_WHITE);
}


AAnimal& AAnimal::operator=(AAnimal const& instance) {
  if (this == &instance)
    return *this;
  type = instance.getType();
  return *this;
}


std::string const& AAnimal::getType(void) const {
  return type;
}


void AAnimal::setType(std::string const& newType) {
  type = newType;
}

