/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 04:15:05 by rmander           #+#    #+#             */
/*   Updated: 2022/01/10 05:06:53 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#include <iostream>
#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm(void)
  : Form("ShrubberyCreationForm", 145, 137) {
  std::cout << "ShrubberyCreationForm constructor" << std::endl;
}


ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target)
  : Form("ShrubberyCreationForm", 145, 137) {
  std::cout << "ShrubberyCreationForm constructor" << std::endl;
}


ShrubberyCreationForm
  ::ShrubberyCreationForm(ShrubberyCreationForm const& instance)
    : Form(instance.getName(), instance.getSignGrade(),
           instance.getExecGrade(), instance.getSigned()) {
  std::cout << "ShrubberyCreationForm copy constructor" << std::endl;
}


ShrubberyCreationForm::~ShrubberyCreationForm(void) {
  std::cout << "ShrubberyCreationForm destructor" << std::endl;
}


void ShrubberyCreationForm::makeTree(std::string const& target) {
  std::string filename = target + "__shrubbery"; 
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


ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    ShrubberyCreationForm const& instance) {
  static_cast<void>(instance);
  throw Bureaucrat::OpOverloadException("Can't create forms.");
}
