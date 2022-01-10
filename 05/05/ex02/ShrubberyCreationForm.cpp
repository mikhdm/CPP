/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 04:15:05 by rmander           #+#    #+#             */
/*   Updated: 2022/01/10 23:16:35 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#include <iostream>
#include <fstream>

#include "Bureaucrat.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(void)
  : AForm("ShrubberyCreationForm", 145, 137), _target("self") {
  std::cout << "ShrubberyCreationForm constructor" << std::endl;
}


ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target)
  : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
  std::cout << "ShrubberyCreationForm constructor" << std::endl;
}


ShrubberyCreationForm
  ::ShrubberyCreationForm(ShrubberyCreationForm const& instance)
    : AForm(instance.getName(), instance.getSignGrade(),
           instance.getExecGrade(), instance.getSigned()),
      _target(instance.getTarget()) {
  std::cout << "ShrubberyCreationForm copy constructor" << std::endl;
}


ShrubberyCreationForm::~ShrubberyCreationForm(void) {
  std::cout << "ShrubberyCreationForm destructor" << std::endl;
}


std::string const& ShrubberyCreationForm::getTarget(void) const {
  return _target;
}


void ShrubberyCreationForm::makeTree(void) const {
  std::string filename = _target + "__shrubbery";
  std::string tree = \
"                     .     .  .      +     .      .          .\n"
"                .       .      .     #       .           .\n"
"                   .      .         ###            .      .      .\n"
"                 .      .   '#:. .:##'##:. .:#'  .      .\n"
"                     .      . '####'###'####'  .\n"
"                  .     '#:.    .:#'###'#:.    .:#'  .        .       .\n"
"             .             '#########'#########'        .        .\n"
"                   .    '#:.  '####'###'####'  .:#'   .       .\n"
"                .     .  '#######''##'##''#######'                  .\n"
"                           .'##'#####'#####'##'           .      .\n"
"               .   '#:. ...  .:##'###'###'##:.  ... .:#'     .\n"
"                 .     '#######'##'#####'##'#######'      .     .\n"
"               .    .     '#####''#######''#####'    .      .\n"
"                       .     '      000      '    .     .\n"
"                  .         .   .   000     .        .       .\n"
"           .. .. ..................O000O........................ ...... ...\n";
  std::ofstream f;
  f.open(filename, std::ofstream::out);
  if (f.fail())
    throw std::exception();
  f << tree;
  f.close();
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
  if (!getSigned())
    throw AForm::ExecutionForbiddenException();
  if (executor.getGrade() > getExecGrade())
    throw AForm::GradeTooLowException();
  makeTree();
}


ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    ShrubberyCreationForm const& instance) {
  static_cast<void>(instance);
  throw Bureaucrat::OpOverloadException("Can't assign forms.");
}
