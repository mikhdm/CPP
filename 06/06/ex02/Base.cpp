/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:57:28 by rmander           #+#    #+#             */
/*   Updated: 2022/01/13 20:28:33 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

#include <cstdlib>
#include <iostream>
#include <exception>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base::~Base(void) {}


static Base* a(void) {
  return new A();
}


static Base* b(void) {
  return new B();
}


static Base* c(void) {
  return new C();
}


Base* generate(void) {
  int const i = std::rand() % 3;
  Base* (*f[])(void) = {&a, &b, &c};

  switch (i) {
    case 0:
      std::cout << "generate: A instance" << std::endl;
      break ;
    case 1:
      std::cout << "generate: B instance" << std::endl;
      break ;
    case 2:
      std::cout << "generate: C instance" << std::endl;
      break ;
    default:
      break ;
  }

  return f[i]();
}


void identify(Base* p) {
  if (!p)
    return ;
  A *aobject = dynamic_cast<A*>(p);
  B *bobject = dynamic_cast<B*>(p);
  C *cobject = dynamic_cast<C*>(p);
  if (aobject) {
    std::cout << "A" << std::endl;
    return ;
  }
  if (bobject) {
    std::cout << "B" << std::endl;
    return ;
  }
  if (cobject) {
    std::cout << "C" << std::endl; 
  }
}

void identify(Base& p) {
  try {
    A& aobject = dynamic_cast<A&>(p);
    static_cast<void>(aobject);
    std::cout << "A" << std::endl;
  }
  catch (std::bad_cast const& e) {}

  try {
    B& bobject = dynamic_cast<B&>(p);
    static_cast<void>(bobject);
    std::cout << "B" << std::endl;
  }
  catch (std::bad_cast const& e) {}

  try {
    C& cobject = dynamic_cast<C&>(p);
    static_cast<void>(cobject);
    std::cout << "C" << std::endl;
  }
  catch (std::bad_cast const& e) {}
}
