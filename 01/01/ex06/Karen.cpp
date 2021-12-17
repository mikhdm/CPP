/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:29:26 by rmander           #+#    #+#             */
/*   Updated: 2021/12/17 21:16:45 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

#include <iostream>


Karen::Karen(void) {}


Karen::Karen(std::string lvl) : _level(level(lvl)) {}


Karen::~Karen(void) {}


KarenLevel Karen::level(std::string level) const {
  size_t i = index(level);
  switch (i) {
    case 0:
      return kLevelDebug;
    case 1:
      return kLevelInfo;
    case 2:
      return kLevelWarning;
    case 3:
      return kLevelError;
    default:
      return kLevelUnknown;
  }
}


KarenLevel Karen::getLevel(void) const {
  return _level;
}


void Karen::setLevel(std::string lvl) {
  _level = level(lvl);
}


void Karen::debug(void) {
  std::cout << SH_COLOR_WHITE
    << "[ DEBUG ]" << std::endl
    << "I love to get extra bacon "
    "for my 7XL-double-cheese-triple-pickle-special-ketchup "
    "burger. I just love it!"
    << SH_COLOR_RESET << std::endl << std::endl;
}


void Karen::info(void) {
  std::cout << SH_COLOR_BLUE
    << "[ INFO ]" << std::endl
    << "I cannot believe adding extra "
    "bacon cost more money. You don't put enough! "
    "If you did I would not have to ask for it!"
    << SH_COLOR_RESET << std::endl << std::endl;
}


void Karen::warning(void) {
  std::cout << SH_COLOR_YELLOW
    << "[ WARNING ]" << std::endl
    << "I think I deserve to have some extra bacon for free. I've been"
    "coming here for years and you just started working here last month."
    << SH_COLOR_RESET << std::endl << std::endl;
}


void Karen::error(void) {
  std::cout << SH_COLOR_RED
    << "[ ERROR ]" << std::endl
    << "This is unacceptable, I want to speak to the manager now."
    << SH_COLOR_RESET << std::endl << std::endl;
}


void Karen::unknown(void) {
  std::cout << SH_COLOR_WHITE
    << "[ Probably complaining about insignificant problems ]"
    << SH_COLOR_RESET << std::endl << std::endl;
}


size_t Karen::index(std::string level) const {
  std::string const levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
  for (size_t i = 0; i < (sizeof(levels) / sizeof(*levels)); ++i) {
    if (level == levels[i]) {
      return i;
    }
  }
  return (SIZE_MAX);
}


void Karen::complain(std::string lvl) {
  void (Karen::*f[])(void) = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error};
  KarenLevel l = level(lvl);
  if (_level == kLevelUnknown || l == kLevelUnknown || l < _level)
    return ;
  (this->*f[l])();
}

