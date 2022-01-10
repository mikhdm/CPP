/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 23:06:01 by rmander           #+#    #+#             */
/*   Updated: 2022/01/11 00:51:45 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"



int main(void) {

  Bureaucrat president("John", 1);
  Intern intern;

  AForm* form;

  form = intern.makeForm("robotomy request", "head");
  if (form) {
    president.signForm(*form);
    president.executeForm(*form);
    delete form;
  }

  form = intern.makeForm("presidential pardon", "bobiboba");
  if (form) {
    president.signForm(*form);
    president.executeForm(*form);
    delete form;
  }

  form = intern.makeForm("shrubbery creation", "hohoho");
  if (form) {
    president.signForm(*form);
    president.executeForm(*form);
    delete form;
  }

  form = intern.makeForm("BOBOTOMY request", "head");
  if (form) {
    president.signForm(*form);
    president.executeForm(*form);
    delete form;
  }

  return (EXIT_SUCCESS);
}
