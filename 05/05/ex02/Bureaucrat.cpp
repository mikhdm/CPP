/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:33:19 by rmander           #+#    #+#             */
/*   Updated: 2022/01/11 15:41:20 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>
#include <string>

#include "AForm.hpp"

unsigned int const Bureaucrat::kGradeMax = 1;
unsigned int const Bureaucrat::kGradeMin = 150;


Bureaucrat::Bureaucrat(void)
  : _name("Bureaucrat"), _grade(Bureaucrat::kGradeMin) {
  std::cout << "Bureaucrat constructor" << std::endl;
}


Bureaucrat::Bureaucrat(std::string const& name, unsigned int grade) : _name(name) {
  if (grade > Bureaucrat::kGradeMin)
    throw GradeTooLowException();
  if (grade < Bureaucrat::kGradeMax)
    throw GradeTooHighException();
  _grade = grade;
  std::cout << "Bureaucrat constructor" << std::endl;
}


Bureaucrat::Bureaucrat(Bureaucrat const& instance) : _name(instance.getName()) {
  if (this == &instance)
    return ;
  _grade = instance.getGrade();
  std::cout << "Bureaucrat copy constructor" << std::endl;
}


Bureaucrat::~Bureaucrat(void) {
  std::cout << "Bureaucrat destructor" << std::endl;
}


Bureaucrat& Bureaucrat::operator=(Bureaucrat const& instance) {
  static_cast<void>(instance);
  throw OpOverloadException("Can't assign bureaucrats.");
}


void Bureaucrat::incGrade(void) {
  if (_grade == Bureaucrat::kGradeMax) {
    throw GradeTooHighException();
  }
  --_grade;
}


void Bureaucrat::decGrade(void) {
  if (_grade == Bureaucrat::kGradeMin) {
    throw GradeTooLowException();
  }
  ++_grade;
}


void Bureaucrat::signForm(AForm& form) {
  try {
    form.beSigned(*this);
    std::cout << _name << " signs " << form.getName() << std::endl;
  } catch (std::exception const& e) {
    std::cerr << _name << " cannot sign " << form.getName()
      << " because " << e.what() << std::endl;
  }
}


void Bureaucrat::executeForm(AForm const& form) {
  try {
    form.execute(*this);
    std::cout << _name << " executes " << form.getName() << std::endl;
  }
  catch (std::exception const& e) {
    std::cerr << _name << " cannot execute " << form.getName()
      << " because " << e.what() << std::endl;
  }
}


std::string const& Bureaucrat::getName(void) const {
  return _name;
}


unsigned int Bureaucrat::getGrade(void) const {
  return _grade;
}


std::ostream& operator<<(std::ostream& o, Bureaucrat const& b) {
  o << b.getName() << ", " << "bureaucrat grade " << b.getGrade();
  return o;
}


const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade is too low :(";
}


const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade is too high :(";
}


Bureaucrat::OpOverloadException::OpOverloadException(
    std::string const& message) : std::exception(), _message(message) {}


Bureaucrat::OpOverloadException::~OpOverloadException(void) throw() {}


const char* Bureaucrat::OpOverloadException::what() const throw() {
  return _message.c_str();
}
