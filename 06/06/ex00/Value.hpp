/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Value.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:14:26 by rmander           #+#    #+#             */
/*   Updated: 2022/01/13 18:17:44 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALUE_HPP
# define VALUE_HPP

# define EDEFAULT 0

enum Type {
  UNSET = -1,
  CHAR = 0,
  INTEGER = 1,
  FLOAT = 2,
  DOUBLE = 3
};


typedef struct {
  bool c;
  bool f;
  bool d;
  bool i;
  bool zpad;
} State;


typedef struct {
  char c;
  float f;
  double d;
  int i;
  Type btype;
  State state;
} Value;


# endif
