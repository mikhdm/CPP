/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 20:54:55 by rmander           #+#    #+#             */
/*   Updated: 2021/12/20 02:44:45 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# define BITS_COUNT     8
# define FIXED_INT_MAX  8388607
# define FIXED_INT_MIN -8388608   

#include <string>
#include <iostream>

class Fixed {
 public:
  Fixed(void);
  Fixed(int const raw);
  Fixed(float const raw);
  Fixed(Fixed const& value);
  virtual ~Fixed(void);
  Fixed& operator=(Fixed const& rvalue); 

  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;
  static void log(std::string const& message);
 private:
  int _value;
  static const int _bits;
  static int const _kIntMax;
  static int const _kIntMin;
};


std::ostream& operator<<(std::ostream& o, Fixed const& instance);


#endif

