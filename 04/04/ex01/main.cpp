/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 02:03:39 by rmander           #+#    #+#             */
/*   Updated: 2022/01/06 02:55:05 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

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

void animals_test(void) {
  Animal **animals = new Animal*[20];

  for (size_t i = 0; i < 10; ++i)
    animals[i] = new Cat();

  for (size_t i = 10; i < 20; ++i)
    animals[i] = new Dog();

  for (size_t i = 0; i < 20; ++i)
    delete animals[i];

  delete [] animals;
}

int main(void) {
  /* brain_test(); */
  animals_test();
  return (0);
}
