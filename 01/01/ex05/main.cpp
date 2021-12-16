/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 20:26:34 by rmander           #+#    #+#             */
/*   Updated: 2021/12/16 20:28:52 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

#include <cstdlib>


int main(void) {
  Karen karen;
  
  karen.complain("INFO");
  karen.complain("WARNING");
  karen.complain("DEBUG");
  karen.complain("ERROR");

  karen.complain("a");
  karen.complain("b");
  karen.complain("c");

  karen.complain("INFOa");
  karen.complain("WARNINGa");
  karen.complain("DEBUGa");
  karen.complain("ERRORa");

  karen.complain("INFO");
  karen.complain("WARNING");
  karen.complain("DEBUG");
  karen.complain("ERROR");
  return (EXIT_SUCCESS);
}
