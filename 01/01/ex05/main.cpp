/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 20:26:34 by rmander           #+#    #+#             */
/*   Updated: 2021/12/16 22:27:06 by rmander          ###   ########.fr       */
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

  Karen *karen2 = new Karen;

  karen2->complain("INFO");
  karen2->complain("WARNING");
  karen2->complain("DEBUG");
  karen2->complain("ERROR");

  karen2->complain("");

  delete karen2;

  return (EXIT_SUCCESS);
}
