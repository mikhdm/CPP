/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 21:12:59 by rmander           #+#    #+#             */
/*   Updated: 2022/01/15 21:13:00 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <list>


int main(void) {
  std::srand(std::time(nullptr));

  std::vector<int> v(20, 0);
  std::list<int> l(50, 0);

  // generate randomized vector
  for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
    *it = rand() % 10; 
  }
  
  // generate randomized list
  for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it) {
    *it = rand() % 100; 
  }

  std::cout << "vector: "; 

  // outputting vector
  for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  
  int value = 4;
  std::cout << "  easyfind(" << value << "): ";
  std::vector<int>::const_iterator itv = easyfind(v, value); 
  if (itv == v.end())
    std::cout << " not found" << std::endl;
  else
    std::cout << " found" << std::endl;
  

  value = 1;
  std::cout << "list: "; 
  // outputting list
  for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it) {
    std::cout << *it << " ";
  }

  std::cout << std::endl;

  std::cout << "  easyfind(" << value << "): ";
  std::list<int>::const_iterator itl = easyfind(l, value); 
  if (itl == l.end())
    std::cout << " not found" << std::endl;
  else
    std::cout << " found" << std::endl;

  return 0;
}
