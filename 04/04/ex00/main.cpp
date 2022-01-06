/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 01:08:59 by rmander           #+#    #+#             */
/*   Updated: 2022/01/06 18:05:59 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include <iostream>

void test(void) {
  Animal* animal = new Animal();
  Animal::log("type: " + animal->getType(), SH_COLOR_WHITE);
  delete animal;

  Animal::log("------", SH_COLOR_WHITE);

  animal = new Dog();
  Animal::log("type: " + animal->getType(), SH_COLOR_WHITE);
  animal->makeSound();
  delete animal;

  Animal::log("------", SH_COLOR_WHITE);

  animal = new Cat();
  Animal::log("type: " + animal->getType(), SH_COLOR_WHITE);
  animal->makeSound();
  delete animal;

  Animal::log("------", SH_COLOR_WHITE);

  Animal animal2;
  Animal animal3(animal2);
  animal3.makeSound();

  Animal::log("------", SH_COLOR_WHITE);
}

int main(void) {

  test();

  std::cout << SH_COLOR_BOLD << SH_COLOR_YELLOW
    << "Subject: " << SH_COLOR_RESET << std::endl;
  {
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete i;
    delete j;
  }

  std::cout << SH_COLOR_BOLD << SH_COLOR_YELLOW
    << "Subject (WrongAnimal & WrongCat): " << SH_COLOR_RESET << std::endl;
  {
    WrongAnimal* meta = new WrongAnimal();
    WrongAnimal* i = new WrongCat();
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the animal sound :(
    meta->makeSound();
    delete meta;

    meta = i;
    meta->makeSound();
    delete meta;
  }
  return (0);
}
