/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 23:06:01 by rmander           #+#    #+#             */
/*   Updated: 2022/01/11 15:33:16 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>


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

  std::cout << "Trying to increment grade for " << clerk << std::endl;
  clerk.incGrade();
  std::cout << clerk << std::endl;


  std::cout << "Trying to decrement grade for " << clerk << std::endl;
  clerk.decGrade();
  std::cout << clerk << std::endl;

  std::cout << "Trying to increment grade for " << president << std::endl;
  try {
    president.incGrade();
  }
  catch (std::exception const& e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "Trying to decrement grade for " << clerk << std::endl;
  try {
    clerk.decGrade();
  }
  catch (std::exception const& e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "Trying to create new with grade 1000" << std::endl;
  try {
    Bureaucrat boba("Boba", 1000);
  }
  catch (std::exception const& e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "Trying to assign to " << president << " from " << clerk << std::endl;
  try {
    president = clerk;
  }
  catch (std::exception const& e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "Trying to create clone of " << president << std::endl;
  Bureaucrat presidenti(president);
  std::cout << presidenti << std::endl;

  return (EXIT_SUCCESS);
}
