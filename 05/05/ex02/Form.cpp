/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 00:16:36 by rmander           #+#    #+#             */
/*   Updated: 2022/01/10 17:58:37 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

#include <iostream>

#include "Bureaucrat.hpp"

unsigned int const Form::kGradeMax = 1;
unsigned int const Form::kGradeMin = 150;


Form::Form(void)
  : _name("Form"), _signGrade(kGradeMin),
    _execGrade(kGradeMin), _signed(false) {
    std::cout << "Form constructor" << std::endl;
}


Form::Form(Form const& instance)
  : _name(instance.getName()), _signGrade(instance.getSignGrade()),
    _execGrade(instance.getExecGrade()), _signed(false) {
  std::cout << "Form copy constructor" << std::endl;
}


Form::Form(std::string const& name,
    unsigned int signGrade, unsigned int execGrade)
  : _name(name), _signGrade(signGrade),
    _execGrade(execGrade), _signed(false) {
    if (_signGrade < Form::kGradeMax || _execGrade < Form::kGradeMax)
      throw Form::GradeTooHighException();
    if (_signGrade > Form::kGradeMin || _execGrade > Form::kGradeMin)
      throw Form::GradeTooLowException();
    std::cout << "Form constructor" << std::endl;
}


Form::Form(std::string const& name,
    unsigned int signGrade, unsigned int execGrade, bool isSigned)
  : _name(name), _signGrade(signGrade),
    _execGrade(execGrade), _signed(isSigned) {
    if (_signGrade < Form::kGradeMax || _execGrade < Form::kGradeMax)
      throw Form::GradeTooHighException();
    if (_signGrade > Form::kGradeMin || _execGrade > Form::kGradeMin)
      throw Form::GradeTooLowException();
    std::cout << "Form constructor" << std::endl;
}


Form::~Form(void) {
  std::cout << "Form destructor" << std::endl;
}


std::string const& Form::getName(void) const {
  return _name;
}


bool Form::getSigned(void) const {
  return _signed;
}


unsigned int Form::getSignGrade(void) const {
  return _signGrade;
}


unsigned int Form::getExecGrade(void) const {
  return _execGrade;
}


void Form::beSigned(Bureaucrat const& b) {
  if (b.getGrade() <= _signGrade) {
    _signed = true;
    return ;
  }
  throw Form::GradeTooLowException();
}

Form& Form::operator=(Form const& instance) {
  static_cast<void>(instance);
  throw Bureaucrat::OpOverloadException("Can't assign forms.");
}


std::ostream& operator<<(std::ostream& o, Form const& f) {
  o << "Form " << f.getName() << std::endl;
  o << "  sign grade required: "<< f.getSignGrade() << std::endl;
  o << "  exec grade required: "<< f.getExecGrade() << std::endl;
  o << "  signed: " << (f.getSigned() ? "Yes" : "No") << std::endl;
  return o;
}


const char* Form::GradeTooLowException::what() const throw() {
  return "Grade is too low";
}


const char* Form::GradeTooHighException::what() const throw() {
  return "Grade is too high";
}


const char* Form::ExecutionForbiddenException::what() const throw() {
  return "Can't execute form";
}
