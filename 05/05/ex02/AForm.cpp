/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 00:16:36 by rmander           #+#    #+#             */
/*   Updated: 2022/01/11 15:41:25 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

unsigned int const AForm::kGradeMax = 1;
unsigned int const AForm::kGradeMin = 150;


AForm::AForm(void)
  : _name("AForm"), _signGrade(kGradeMin),
    _execGrade(kGradeMin), _signed(false) {
    std::cout << "AForm constructor" << std::endl;
}


AForm::AForm(AForm const& instance)
  : _name(instance.getName()), _signGrade(instance.getSignGrade()),
    _execGrade(instance.getExecGrade()), _signed(false) {
  std::cout << "AForm copy constructor" << std::endl;
}


AForm::AForm(std::string const& name,
    unsigned int signGrade, unsigned int execGrade)
  : _name(name), _signGrade(signGrade),
    _execGrade(execGrade), _signed(false) {
    if (_signGrade < AForm::kGradeMax || _execGrade < AForm::kGradeMax)
      throw AForm::GradeTooHighException();
    if (_signGrade > AForm::kGradeMin || _execGrade > AForm::kGradeMin)
      throw AForm::GradeTooLowException();
    std::cout << "AForm constructor" << std::endl;
}


AForm::AForm(std::string const& name,
    unsigned int signGrade, unsigned int execGrade, bool isSigned)
  : _name(name), _signGrade(signGrade),
    _execGrade(execGrade), _signed(isSigned) {
    if (_signGrade < AForm::kGradeMax || _execGrade < AForm::kGradeMax)
      throw AForm::GradeTooHighException();
    if (_signGrade > AForm::kGradeMin || _execGrade > AForm::kGradeMin)
      throw AForm::GradeTooLowException();
    std::cout << "AForm constructor" << std::endl;
}


AForm::~AForm(void) {
  std::cout << "AForm destructor" << std::endl;
}


std::string const& AForm::getName(void) const {
  return _name;
}


bool AForm::getSigned(void) const {
  return _signed;
}


unsigned int AForm::getSignGrade(void) const {
  return _signGrade;
}


unsigned int AForm::getExecGrade(void) const {
  return _execGrade;
}


void AForm::beSigned(Bureaucrat const& b) {
  if (b.getGrade() <= _signGrade) {
    _signed = true;
    return ;
  }
  throw AForm::GradeTooLowException();
}


AForm& AForm::operator=(AForm const& instance) {
  static_cast<void>(instance);
  throw Bureaucrat::OpOverloadException("Can't assign forms.");
}


std::ostream& operator<<(std::ostream& o, AForm const& f) {
  o << "Form " << f.getName() << std::endl;
  o << "  sign grade required: "<< f.getSignGrade() << std::endl;
  o << "  exec grade required: "<< f.getExecGrade() << std::endl;
  o << "  signed: " << (f.getSigned() ? "Yes" : "No") << std::endl;
  return o;
}


const char* AForm::GradeTooLowException::what() const throw() {
  return "Grade is too low";
}


const char* AForm::GradeTooHighException::what() const throw() {
  return "Grade is too high";
}


const char* AForm::ExecutionForbiddenException::what() const throw() {
  return "Form is not executable";
}
