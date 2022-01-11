/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 00:12:36 by rmander           #+#    #+#             */
/*   Updated: 2022/01/12 00:16:54 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <limits>
#include <iostream>


int main(int argc, char **argv) {
  if (argc != 1)
  {
    std::cerr << "Invalid number of arguments." << std::endl;
    return (EXIT_FAILURE);
  }
  return (EXIT_SUCCESS);
}
