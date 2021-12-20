/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 20:54:55 by rmander           #+#    #+#             */
/*   Updated: 2021/12/20 18:14:36 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# define BITS_COUNT 8

#include <string>

class Fixed {
 public:
  Fixed(void);
  Fixed(Fixed const& value);
  virtual ~Fixed(void);
  Fixed& operator=(Fixed const& rvalue); 

  int getRawBits(void) const;
  void setRawBits(int const raw);
  static void log(std::string const& message);
 private:
  int _value;
  static const int _bits;
};


#endif // FIXED_H

