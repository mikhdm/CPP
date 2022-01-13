/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:52:23 by rmander           #+#    #+#             */
/*   Updated: 2022/01/13 20:27:01 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef BASE_HPP
# define BASE_HPP


class Base {
 public:
  virtual ~Base(void);
};


Base* generate(void);
void  identify(Base* p);
void  identify(Base& p);

# endif

