/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:26:20 by rmander           #+#    #+#             */
/*   Updated: 2022/01/13 19:27:28 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include <string>

#include <stdint.h>

typedef struct {
  std::string s;
  int         v;
  float       f;
  double      d;
  int         *vp;
} Data;

uintptr_t serialize(Data* ptr);
Data*     deserialize(uintptr_t raw);

# endif
