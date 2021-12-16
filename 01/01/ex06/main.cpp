/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 20:26:34 by rmander           #+#    #+#             */
/*   Updated: 2021/12/16 22:43:16 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

#include <cstdlib>
#include <iostream>


int main(int argc, char **argv) {
  Karen karen;

  if (argc == 1)
  {
    std::cerr << "Insufficient number of arguments" << std::endl;
    std::exit(1);
  }
  size_t index = karen.index(argv[1]);


  switch (level) {
    case "DEBUG":
      karen.complain(level);
      break ;

  }

  return (EXIT_SUCCESS);
}
