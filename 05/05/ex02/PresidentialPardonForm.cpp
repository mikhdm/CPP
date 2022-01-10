/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 22:48:56 by rmander           #+#    #+#             */
/*   Updated: 2022/01/10 23:14:45 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(void)
  : AForm("PresidentialPardonForm", 25, 5), _target("self") {
  std::cout << "PresidentialPardonForm constructor" << std::endl;
}


PresidentialPardonForm::PresidentialPardonForm(std::string const& target)
  : AForm("PresidentialPardonForm", 25, 5), _target(target) {
  std::cout << "PresidentialPardonForm constructor" << std::endl;
}


PresidentialPardonForm
  ::PresidentialPardonForm(PresidentialPardonForm const& instance)
    : AForm(instance.getName(), instance.getSignGrade(),
           instance.getExecGrade(), instance.getSigned()),
      _target(instance.getTarget()) {
  std::cout << "PresidentialPardonForm copy constructor" << std::endl;
}


PresidentialPardonForm::~PresidentialPardonForm(void) {
  std::cout << "PresidentialPardonForm destructor" << std::endl;
}


std::string const& PresidentialPardonForm::getTarget(void) const {
  return _target;
}


void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
  if (!getSigned())
    throw AForm::ExecutionForbiddenException();
  if (executor.getGrade() > getExecGrade())
    throw AForm::GradeTooLowException();
  std::cout << _target << " has been pardoned by Zafod Beeblebrox"
    << std::endl;
}


PresidentialPardonForm& PresidentialPardonForm::operator=(
    PresidentialPardonForm const& instance) {
  static_cast<void>(instance);
  throw Bureaucrat::OpOverloadException("Can't assign forms.");
}


