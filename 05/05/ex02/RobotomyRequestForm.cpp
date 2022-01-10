/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:03:54 by rmander           #+#    #+#             */
/*   Updated: 2022/01/10 23:15:32 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

#include <iostream>

#include "Bureaucrat.hpp"
#include "AForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(void)
  : AForm("RobotomyRequestForm", 72, 45), _target("self") {
  std::cout << "RobotomyRequestForm constructor" << std::endl;
}


RobotomyRequestForm::RobotomyRequestForm(std::string const& target)
  : AForm("RobotomyRequestForm", 72, 45), _target(target) {
  std::cout << "RobotomyRequestForm constructor" << std::endl;
}


RobotomyRequestForm
  ::RobotomyRequestForm(RobotomyRequestForm const& instance)
    : AForm(instance.getName(), instance.getSignGrade(),
           instance.getExecGrade(), instance.getSigned()),
      _target(instance.getTarget()) {
  std::cout << "RobotomyRequestForm copy constructor" << std::endl;
}


RobotomyRequestForm::~RobotomyRequestForm(void) {
  std::cout << "RobotomyRequestForm destructor" << std::endl;
}


std::string const& RobotomyRequestForm::getTarget(void) const {
  return _target;
}


void RobotomyRequestForm::tellMessage(void) const {
  size_t j = 0;

  if (std::rand() % 2) {
    size_t limit = (std::rand() % 10) + 2;
    for (size_t i = 0; i < limit; ++i)
    {
      j = 0;
      std::cout << '\a' << "Drilling noise..." << std::endl;
      while (j++ < 150000000)
        ;
      std::cout << "\033[A\33[2K\r";
    }
    
    std::cout << _target << " has been robotomized successfully" << std::endl;
  }
  else
    throw RobotomyRequestForm::FailureException();
}


void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
  if (!getSigned())
    throw AForm::ExecutionForbiddenException();
  if (executor.getGrade() > getExecGrade())
    throw AForm::GradeTooLowException();
  tellMessage();
}

const char* RobotomyRequestForm::FailureException::what() const throw() {
  return "it's a failure";
}


RobotomyRequestForm& RobotomyRequestForm::operator=(
    RobotomyRequestForm const& instance) {
  static_cast<void>(instance);
  throw Bureaucrat::OpOverloadException("Can't assign forms.");
}

