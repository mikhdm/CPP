/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:41:04 by rmander           #+#    #+#             */
/*   Updated: 2021/12/15 15:57:02 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>


int main(void) {
  std::string brain = "HI THIS IS BRAIN";

  std::string* stringPTR = &brain;
  std::string& stringREF = brain;

  std::cout<<"Address of the string brain: "<<&brain<<std::endl;
  std::cout<<"Address of the string brain (via stringPTR): "<<stringPTR<<std::endl;
  std::cout<<"Adddress of the string brain (via stringREF): "<<&stringREF<<std::endl;

  return (EXIT_SUCCESS);
}

