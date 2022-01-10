/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 04:15:05 by rmander           #+#    #+#             */
/*   Updated: 2022/01/10 17:59:21 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#include <iostream>
#include <fstream>

#include "Bureaucrat.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(void)
  : Form("ShrubberyCreationForm", 145, 137), _target("self") {
  std::cout << "ShrubberyCreationForm constructor" << std::endl;
}


ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target)
  : Form("ShrubberyCreationForm", 145, 137), _target(target) {
  std::cout << "ShrubberyCreationForm constructor" << std::endl;
}


ShrubberyCreationForm
  ::ShrubberyCreationForm(ShrubberyCreationForm const& instance)
    : Form(instance.getName(), instance.getSignGrade(),
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


void ShrubberyCreationForm::makeTree(void) {
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
  if (!_signed)
    throw Form::ExecutionForbiddenException();
  if (executor.getGrade() > _execGrade) 
    throw Form::GradeTooLowException();
  makeTree();
}


ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    ShrubberyCreationForm const& instance) {
  static_cast<void>(instance);
  throw Bureaucrat::OpOverloadException("Can't create forms.");
}
