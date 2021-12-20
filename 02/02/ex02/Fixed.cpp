/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 20:55:16 by rmander           #+#    #+#             */
/*   Updated: 2021/12/20 18:11:49 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <cmath>
#include <iostream>

const int Fixed::_bits = BITS_COUNT;
const int Fixed::_kIntMax = FIXED_INT_MAX; 
const int Fixed::_kIntMin = FIXED_INT_MIN;


void Fixed::log(std::string const& message) {
  std::cout << message << std::endl;
}


Fixed::Fixed(void) : _value(0) {
  Fixed::log("Default constructor called");
}


bool Fixed::valid(int const value) const {
  long const v = static_cast<long>(value);
  if (v < Fixed::_kIntMin || v > Fixed::_kIntMax) 
    return (false);
  return (true);
}


bool Fixed::valid(float const value) const {
  long const v = static_cast<long>(value);
  if ((v < static_cast<long>(std::numeric_limits<int>::min()))
      || (v > static_cast<long>(std::numeric_limits<int>::max())))
    return (false);
  return (true);
}


Fixed::Fixed(int const raw) : _value(0) {
  log("Int constructor called");
  if (!valid(raw))
      std::cerr << "Fixed buffer overflow." << std::endl;
  _value = raw << Fixed::_bits;
}


Fixed::Fixed(float const raw) : _value(0) {
  log("Float constructor called");
  if (!valid(raw))
    std::cerr << "Fixed buffer overflow." << std::endl;
  _value = static_cast<int>(roundf(raw * (1 << Fixed::_bits)));
}


Fixed::Fixed(Fixed const& instance) : _value(0) {
  Fixed::log("Copy constructor called");
  if (this == &instance)
    return ;
  *this = instance;
}


Fixed::~Fixed(void) {
  Fixed::log("Destructor called");
}


int Fixed::getRawBits(void) const {
  return _value;
}


void Fixed::setRawBits(int const raw) {
  _value = raw;
}


int Fixed::toInt(void) const {
  return _value >> Fixed::_bits;
}


float Fixed::toFloat(void) const {
  return static_cast<float>(_value) / (1 << Fixed::_bits);
}


Fixed& Fixed::operator=(Fixed const& instance) {
  Fixed::log("Assignation operator called");
  if (this == &instance)
    return *this;
  _value = instance.getRawBits();
  return *this;
}


std::ostream& operator<<(std::ostream& o, Fixed const& instance) {
  std::cout << instance.toFloat(); 
  return o;
}
