/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 23:06:01 by rmander           #+#    #+#             */
/*   Updated: 2022/01/10 02:18:28 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>

#include "Form.hpp"

int main(void) {
  
  Bureaucrat president("John", 1);
  Bureaucrat vice("David", 2);
  Bureaucrat finlead("McLaren", 3);
  Bureaucrat clerk("Matthew", 150);

  std::cout << std::endl << "Investement bank \"Winds of the East\" staff: " << std::endl;
  std::cout << president << std::endl;
  std::cout << vice << std::endl;
  std::cout << finlead << std::endl;
  std::cout << clerk << std::endl << std::endl;;

  Form a1("President exclusion", 1, 1); 
  Form a2("Vice president exclusion", 2, 1);
  Form a150("Generic Exclusion", 10, 100);

  std::cout << a1;
  std::cout << a2;
  std::cout << a150;
  
  std::cout << std::endl;
  president.signForm(&a150);
  std::cout << a150;

  std::cout << std::endl;

  clerk.signForm(&a1);
  std::cout << a1;

  std::cout << std::endl;

  std::cout << "Trying create form with too low sign grade: " << std::endl;
  try {
    Form a1000("Nonexistent form", 151, 100);
  } catch (Form::GradeTooLowException const &e) {
    std::cout << e.what() << std::endl; 
  }

  std::cout << std::endl << "Trying create form with too low exec grade: " << std::endl;
  try {
    Form a1000("Nonexistent form", 149, 151);
  } catch (Form::GradeTooLowException const &e) {
    std::cout << e.what() << std::endl; 
  }

  std::cout << std::endl << "Trying create form with too high sign grade: " << std::endl;
  try {
    Form a1000("Nonexistent form", 0, 1);
  } catch (Form::GradeTooHighException const &e) {
    std::cout << e.what() << std::endl; 
  }

  std::cout << std::endl << "Trying create form with error grades: " << std::endl;
  try {
    Form a1000("Nonexistent form", 151, 0);
  }
  catch (Form::GradeTooLowException const &e) {
    std::cout << e.what() << std::endl; 
  }
  catch (Form::GradeTooHighException const &e) {
    std::cout << e.what() << std::endl; 
  }

  return (EXIT_SUCCESS);
}
