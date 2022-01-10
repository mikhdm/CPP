/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 23:20:24 by rmander           #+#    #+#             */
/*   Updated: 2022/01/11 00:48:25 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

#include <iostream>
#include <cctype>

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


const size_t Intern::kFormsCount = 3;


static std::string strtolower(std::string const& str) {
  std::string out;
  out.reserve(str.length());
  for (size_t i = 0; i < str.length(); ++ i)
    out.push_back(static_cast<char>(std::tolower(str[i])));
  return out;
}


Intern::Intern(void) {
  std::cout << "Intern constructor" << std::endl;
}


Intern::~Intern(void) {
  std::cout << "Intern destructor" << std::endl;
}


Intern::Intern(Intern const& instance) {
  *this = instance;
  std::cout << "Intern copy constructor" << std::endl;
}


Intern& Intern::operator=(Intern const& instance) {
  static_cast<void>(instance);
  return *this;
}

AForm* Intern::shrubbery(std::string const& target) {
  return new ShrubberyCreationForm(target);
}


AForm* Intern::presidential(std::string const& target) {
  return new PresidentialPardonForm(target);
}


AForm* Intern::robotomy(std::string const& target) {
  return new RobotomyRequestForm(target);
}


size_t Intern::indexOf(std::string const* names, std::string const& name) {
  for (size_t i = 0; i < Intern::kFormsCount; ++i) {
    if (names[i] == name)
      return i;
  }
  throw Intern::OutOfRangeException();
}


AForm* Intern::makeForm(std::string const& name, std::string const& target) {
  size_t i = 0;
  std::string names[] = {"robotomy request", "shrubbery creation", "presidential pardon"};
  AForm* (Intern::*f[])(std::string const&) = {&Intern::robotomy, &Intern::shrubbery, &Intern::presidential};

  try {
    i = indexOf(names, strtolower(name));
  }
  catch (OutOfRangeException const& e) {
    std::cout << "Appropriate form has not been found for: " << name << std::endl; 
    return nullptr;
  }

  AForm* form = (this->*f[i])(target);
  std::cout << "Intern creates " << form->getName() << std::endl;
  return form;
}


const char* Intern::OutOfRangeException::what() const throw() {
  return "Index out of range";
}
