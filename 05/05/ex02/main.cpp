/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 23:06:01 by rmander           #+#    #+#             */
/*   Updated: 2022/01/11 15:43:50 by rmander          ###   ########.fr       */
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


void testForm(Bureaucrat& b, Bureaucrat& clerk, AForm& form) {

  std::cout << form << std::endl;
  std::cout << b << " tries to execute " << form << std::endl;

  try {
    b.executeForm(form);
  }
  catch (std::exception const& e) {
    std::cout << e.what() << std::endl;
  }

  b.signForm(form);
  std::cout << form << std::endl;

  try {
    b.executeForm(form);
  } 
  catch (std::exception const& e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << std::endl;

  try {
    clerk.executeForm(form);
  } 
  catch (std::exception const& e) {
    std::cout << e.what() << std::endl;
  }
}


int main(void) {

  std::srand(std::time(nullptr));
  
  Bureaucrat president("John", 1);
  Bureaucrat vice("David", 2);
  Bureaucrat finlead("McLaren", 3);
  Bureaucrat clerk("Matthew", 150);

  std::cout << std::endl << "Investement bank \"Winds of the East\" staff: " << std::endl;
  std::cout << president << std::endl;
  std::cout << vice << std::endl;
  std::cout << finlead << std::endl;
  std::cout << clerk << std::endl << std::endl;;
  
  ShrubberyCreationForm sh1("christmas");
  RobotomyRequestForm r1("hand");
  PresidentialPardonForm p1("Matthew");

  testForm(president, clerk, sh1);

  std::cout << std::endl;

  testForm(president, clerk, r1);
  
  std::cout << std::endl;

  testForm(president, clerk, p1);

  std::cout << std::endl;

  return (EXIT_SUCCESS);
}
