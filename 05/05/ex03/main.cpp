/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 23:06:01 by rmander           #+#    #+#             */
/*   Updated: 2022/01/11 15:59:54 by rmander          ###   ########.fr       */
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


static void applyForm(Bureaucrat &b, AForm *form) {
    try {
      b.signForm(*form);
      b.executeForm(*form);
    }
    catch (std::exception const& e) {
      std::cout << e.what() << std::endl;
    }
}


int main(void) {
  Bureaucrat president("John", 1);
  Intern intern;
  AForm* form = nullptr;

  form = intern.makeForm("robotomy request", "head");
  if (form) {
    applyForm(president, form);
    delete form;
  }

  form = intern.makeForm("presidential pardon", "bobiboba");
  if (form) {
    applyForm(president, form);
    delete form;
  }

  form = intern.makeForm("shrubbery creation", "hohoho");
  if (form) {
    applyForm(president, form);
    delete form;
  }

  form = intern.makeForm("BOBOTOMY request", "head");
  if (form) {
    applyForm(president, form);
    delete form;
  }

  return (EXIT_SUCCESS);
}
