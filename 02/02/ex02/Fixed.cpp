/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 20:55:16 by rmander           #+#    #+#             */
/*   Updated: 2022/01/09 21:02:13 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <cmath>
#include <iostream>

int const Fixed::_bits = BITS_COUNT;
int const Fixed::_kIntMax = FIXED_INT_MAX; 
int const Fixed::_kIntMin = FIXED_INT_MIN;


void Fixed::log(std::string const& message) {
  std::cout << message << std::endl;
}


Fixed::Fixed(void) : _value(0) {}


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
  if (!valid(raw))
  {
      std::cerr << "Fixed buffer overflow." << std::endl;
      return ;
  }
  _value = raw << Fixed::_bits;
}


Fixed::Fixed(float const raw) : _value(0) {
  if (!valid(raw))
  {
    std::cerr << "Fixed buffer overflow." << std::endl;
    return ;
  }
  _value = static_cast<int>(roundf(raw * (1 << Fixed::_bits)));
}


Fixed::Fixed(Fixed const& instance) : _value(0) {
  if (this == &instance)
    return ;
  *this = instance;
}


Fixed::~Fixed(void) {}


int Fixed::getRawBits(void) const {
  return _value;
}


void Fixed::setRawBits(int const raw) {
  if (!valid(raw))
  {
    std::cerr << "Fixed buffer overflow." << std::endl;
    return ;
  }
  _value = raw;
}


int Fixed::toInt(void) const {
  if (_value < 0)
    return -(~_value >> Fixed::_bits); 
  return _value >> Fixed::_bits;
}


float Fixed::toFloat(void) const {
  float v = static_cast<float>(_value); 
  return v / (1 << Fixed::_bits);
}


Fixed& Fixed::operator=(Fixed const& instance) {
  if (this == &instance)
    return *this;
  _value = instance.getRawBits();
  return *this;
}


std::ostream& operator<<(std::ostream& o, Fixed const& instance) {
  std::cout << instance.toFloat();
  return o;
}


// Comparison operators overloading

bool Fixed::operator<(Fixed const& rvalue) const {
  return _value < rvalue.getRawBits();
}


bool Fixed::operator>(Fixed const& rvalue) const {
  return rvalue < *this;
}


bool Fixed::operator<=(Fixed const& rvalue) const {
  return !(*this > rvalue);
}


bool Fixed::operator>=(Fixed const& rvalue) const {
  return !(*this < rvalue);
}


bool Fixed::operator!=(Fixed const& rvalue) const {
  return !(*this == rvalue);
}


bool Fixed::operator==(Fixed const& rvalue) const {
  return _value == rvalue.getRawBits();
}


// Arithmetic operator overloading

Fixed Fixed::operator+(Fixed const& rvalue) const {
  float val = toFloat() + rvalue.toFloat(); 
  return Fixed(val);
}


Fixed Fixed::operator-(Fixed const& rvalue) const {
  float value = toFloat() - rvalue.toFloat();
  return Fixed(value);
}


Fixed Fixed::operator*(Fixed const& rvalue) const {
  float value = toFloat() * rvalue.toFloat();
  return Fixed(value);
}


Fixed Fixed::operator/(Fixed const& rvalue) const {
  int rval = rvalue.getRawBits();
  if (rval == 0)
  {
    std::cerr << "Division by zero" << std::endl;
    return *this;
  }
  Fixed a;
  float val = (static_cast<float>(_value) / rvalue.getRawBits()) * (1 << Fixed::_bits);
  a.setRawBits(val);
  return a;
}


// Prefix increment

Fixed& Fixed::operator++(void) {
  setRawBits(_value + 1);
  return *this;
}


// Postfix increment 

Fixed Fixed::operator++(int zero) {
  static_cast<void>(zero);

  Fixed tmp = *this;
  operator++();
  return tmp;
}


// Prefix decrement

Fixed& Fixed::operator--(void) {
  setRawBits(_value - 1);
  return *this;
}


// Postfix decrement
Fixed Fixed::operator--(int zero) {
  static_cast<void>(zero);

  Fixed tmp = *this;
  operator--();
  return tmp;
}


Fixed& Fixed::min(Fixed& l, Fixed& r) {
  return (l < r) ? l : r;
}


Fixed const& Fixed::min(Fixed const& l, Fixed const& r) {
  return (l < r) ? l : r;
}


Fixed& Fixed::max(Fixed& l, Fixed& r) {
  return (l < r) ? r : l;
}


Fixed const& Fixed::max(Fixed const& l, Fixed const& r) {
  return (l < r) ? r : l;
}

