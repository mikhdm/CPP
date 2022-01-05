/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 02:03:39 by rmander           #+#    #+#             */
/*   Updated: 2022/01/06 02:11:17 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

#include <iostream>

void brain_test(void) {
  Brain b;
  b.setIdea(0, "Black hat");
  b.setIdea(22, "White rose");
  b.setIdea(84, "Green light");
  
  std::string idea;
  std::cout << "B ideas: " << std::endl;
  for (unsigned int i = 0; i < IDEAS_COUNT; ++i) {
    idea = b.getIdea(i);
    if (!idea.empty())
      std::cout << i << ": " << idea << std::endl;
  }

  Brain c(b);

  std::cout << "C ideas: " << std::endl;
  for (unsigned int i = 0; i < IDEAS_COUNT; ++i) {
    idea = c.getIdea(i);
    if (!idea.empty())
      std::cout << i << ": " << idea << std::endl;
  }
}

int main(void) {
  brain_test();
  return (0);
}
