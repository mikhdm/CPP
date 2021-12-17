/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 20:26:34 by rmander           #+#    #+#             */
/*   Updated: 2021/12/17 21:01:44 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

#include <cstdlib>
#include <iostream>


int main(int argc, char **argv) {
  if (argc == 1)
  {
    std::cerr << "Insufficient number of arguments" << std::endl;
    std::exit(1);
  }
  Karen karen(argv[1]);
  if (karen.getLevel() == kLevelUnknown)
  {
    karen.unknown();
    return (EXIT_SUCCESS);
  }
  karen.complain("DEBUG");
  karen.complain("INFO");
  karen.complain("WARNING");
  karen.complain("ERROR");
  return (EXIT_SUCCESS);
}
