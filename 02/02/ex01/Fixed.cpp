/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 20:55:16 by rmander           #+#    #+#             */
/*   Updated: 2021/12/20 02:55:36 by rmander          ###   ########.fr       */
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


Fixed::Fixed(int const raw) : _value(0) {
  log("Int constructor called");
  _value = raw << Fixed::_bits;
}


Fixed::Fixed(float const raw) : _value(0) {
  log("Float constructor called");
  _value = raw * (1 << Fixed::_bits);
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
  Fixed::log("getRawBits member function called");
  return _value;
}


void Fixed::setRawBits(int const raw) {
  _value = raw;
}


Fixed& Fixed::operator=(Fixed const& instance) {
  Fixed::log("Assignation operator called");
  if (this == &instance)
    return *this;
  setRawBits(instance.getRawBits());
  return *this;
}

