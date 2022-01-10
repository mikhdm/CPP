/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 23:06:01 by rmander           #+#    #+#             */
/*   Updated: 2022/01/10 17:46:37 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"

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

  ShrubberyCreationForm shform("super");
  
  return (EXIT_SUCCESS);
}
