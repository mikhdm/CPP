/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:55:16 by rmander           #+#    #+#             */
/*   Updated: 2022/01/13 20:38:56 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "X.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>


int main(void) {
  std::srand(std::time(nullptr));

  std::cout << "IDENTIFYING VIA POINTER: " << std::endl << std::endl;
  {
    for (size_t i = 0; i < 10; ++i) {
      Base *base = generate();
      std::cout << "identify: ";
      identify(base);
      std::cout << std::endl;
      delete base;
    }
    Base *x = new X();
    std::cout << "identify (test out of check class X): ";
    identify(x);
    std::cout << std::endl;
    delete x;
  }

  std::cout << std::endl << "IDENTIFYING VIA REFERENCE: " << std::endl << std::endl;
  {
    for (size_t i = 0; i < 10; ++i) {
      Base *base = generate();
      std::cout << "identify: ";
      identify(*base);
      std::cout << std::endl;
      delete base;
    }
    Base *x = new X();
    std::cout << "identify (test out of check class X): ";
    identify(*x);
    std::cout << std::endl;
    delete x;
  }
  
  return (EXIT_SUCCESS);
}
