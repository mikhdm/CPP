/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 01:00:24 by rmander           #+#    #+#             */
/*   Updated: 2022/01/06 18:44:51 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

#include <iostream>


Brain::Brain(void) {
  std::cout << "Brain constructor" << std::endl;
}


Brain::Brain(Brain const& instance) {
  if (this == &instance)
    return ;
  *this = instance;
  std::cout << "Brain copy constructor" << std::endl;
}


Brain::~Brain(void) {
  std::cout << "Brain destructor" << std::endl;
}


std::string const& Brain::getIdea(unsigned int n) const {
  return ideas[n % IDEAS_COUNT];
}


void Brain::setIdea(unsigned int n, std::string idea) {
  if (n >= IDEAS_COUNT)
    return ; 
  ideas[n] = idea;
}


Brain& Brain::operator=(Brain const& instance) {
  if (this == &instance)
    return *this;
  for (unsigned int i = 0; i < IDEAS_COUNT; ++i) {
    setIdea(i, instance.getIdea(i));
  }
  return *this;
}
