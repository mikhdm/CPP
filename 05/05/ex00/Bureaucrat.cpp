/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:33:19 by rmander           #+#    #+#             */
/*   Updated: 2022/01/08 22:30:35 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


unsigned int Bureaucrat::gradeMax = 1;
unsigned int Bureaucrat::gradeMin = 150;


const char* Bureaucrat::GradeTooLowException::what() const {
  return "Grade is too low :(";
}


const char* Bureaucrat::GradeTooHighException::what() const {
  return "Grade is too high :(";
}


Bureaucrat::Bureaucrat(void) : _grade(Bureaucrat::gradeMin) {
  std::cout << "Bureaucrat constructor" << std::endl;
}


Bureaucrat::Bureaucrat(unsigned int grade) {
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

}




Bureaucrat& Bureaucrat::operator=(Bureaucrat const& instance) {
  if (this == &instance)
    return *this;
}


std::string const& Bureaucrat::getName(void) const {
  return _name;
}

unsigned int Bureaucrat::getGrade(void) const {
  return _grade;
}
