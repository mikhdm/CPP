/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:29:26 by rmander           #+#    #+#             */
/*   Updated: 2021/12/16 22:33:01 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

#include <iostream>


Karen::Karen(void) {}


Karen::~Karen(void) {}


void Karen::debug(void) {
  std::cout << SH_COLOR_WHITE
    << "I love to get extra bacon "
    "for my 7XL-double-cheese-triple-pickle-special-ketchup "
    "burger. I just love it!"
    << SH_COLOR_RESET << std::endl;
}


void Karen::info(void) {
  std::cout << SH_COLOR_BLUE
    << "I cannot believe adding extra "
    "bacon cost more money. You don't put enough! "
    "If you did I would not have to ask for it!"
    << SH_COLOR_RESET << std::endl;
}


void Karen::warning(void) {
  std::cout << SH_COLOR_YELLOW
    << "I think I deserve to have some extra bacon for free. I've been"
    "coming here for years and you just started working here last month."
    << SH_COLOR_RESET << std::endl;
}


void Karen::error(void) {
  std::cout << SH_COLOR_RED
    << "This is unacceptable, I want to speak to the manager now."
    << SH_COLOR_RESET << std::endl;
}


size_t Karen::index(std::string level) const {
  std::string const levels[] = {"INFO", "DEBUG", "WARNING", "ERROR"};
  for (size_t i = 0; i < (sizeof(levels) / sizeof(*levels)); ++i) {
    if (level == levels[i]) {
      return i;
    }
  }
  return (SIZE_MAX);
}


void Karen::complain(std::string level) {
  void (Karen::*f[])(void) = {&Karen::info, &Karen::debug, &Karen::warning, &Karen::error};
  size_t  idx;

  idx = index(level);
  if (idx == SIZE_MAX)
    return ;
  (this->*f[idx])();
}

