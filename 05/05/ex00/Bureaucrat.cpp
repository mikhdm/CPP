/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:33:19 by rmander           #+#    #+#             */
/*   Updated: 2022/01/08 23:12:31 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>


unsigned int Bureaucrat::gradeMax = 1;
unsigned int Bureaucrat::gradeMin = 150;


Bureaucrat::Bureaucrat(void)
  : _name("Bureaucrat"), _grade(Bureaucrat::gradeMin) {
  std::cout << "Bureaucrat constructor" << std::endl;
}


Bureaucrat::Bureaucrat(std::string const& name, unsigned int grade) : _name(name) {
  if (grade > Bureaucrat::gradeMin)
    throw GradeTooLowException();
  if (grade < Bureaucrat::gradeMax)
    throw GradeTooHighException();
  _grade = grade;
  std::cout << "Bureaucrat constructor" << std::endl;
}


Bureaucrat::Bureaucrat(Bureaucrat const& instance) : _name(instance.getName()) {
  if (this == &instance)
    return ;
  *this = instance;
  std::cout << "Bureaucrat copy constructor" << std::endl;
}


Bureaucrat::~Bureaucrat(void) {
  std::cout << "Bureaucrat destructor" << std::endl;
}


Bureaucrat& Bureaucrat::operator=(Bureaucrat const& instance) {
  if (this == &instance)
    return *this;
  throw std::exception("Can't assign bureaucrats.");
}


void Bureaucrat::incGrade(void) {
  if (_grade == Bureaucrat::gradeMax) {
    throw GradeTooHighException();
  }
  --_grade;
}


void Bureaucrat::decGrade(void) {
  if (_grade == Bureaucrat::gradeMin) {
    throw GradeTooLowException();
  }
  ++_grade;
}


std::string const& Bureaucrat::getName(void) const {
  return _name;
}


unsigned int Bureaucrat::getGrade(void) const {
  return _grade;
}


std::ostream& operator<<(std::ostream const& o, Bureaucrat const& b) {
  std::cout << b.getName() << ", " << "bureaucrat grade " << b.getGrade() << std::endl; 
}


const char* Bureaucrat::GradeTooLowException::what() const {
  return "Grade is too low :(";
}


const char* Bureaucrat::GradeTooHighException::what() const {
  return "Grade is too high :(";
}
