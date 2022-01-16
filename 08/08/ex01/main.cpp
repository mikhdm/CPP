/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 21:54:35 by rmander           #+#    #+#             */
/*   Updated: 2022/01/16 04:46:24 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <limits>


int main(void) {
  std::srand(std::time(nullptr));
  {
    Span sp(5);

    std::cout << "Adding numbers to span:" << std::endl;
    for (size_t i = 0; i < 5; ++i) { 
      sp.addNumber(i);
    }
    std::cout << "  " << sp << std::endl;

    std::cout << "Trying to add more than size available:" << std::endl;
    try {
      sp.addNumber(0);

    }
    catch(std::exception const& e) {
      std::cout << "  " << e.what() << std::endl;
    }
  
    std::cout << "Copying via copy constructor:" << std::endl;
    Span sp2(sp);
    std::cout << "  " << sp2 << std::endl;


    std::cout << "Assigning via assign op overload:" << std::endl;
    Span sp3(4);
    Span sp4(5);
    std::cout << "  sp left capacity: " << sp3.capacity() << std::endl;
    std::cout << "  sp right capacity: " << sp4.capacity() << std::endl;
    try {
      sp3 = sp4;
    }
    catch (std::exception const& e) {
      std::cout << "  " << e.what() << std::endl;
    }
    
    std::cout << "Assigning via assign op overload (ok case):" << std::endl;
    std::cout << "  sp left capacity: " << sp4.capacity() << std::endl;
    std::cout << "  sp right capacity: " << sp.capacity() << std::endl;
    sp4 = sp; 
    std::cout << "  " << sp4 << std::endl;
  }

  {
    Span sp(10);
    std::vector<int> mirror(10, 42);

    Span sp2(50);
    std::vector<int> big(100, -1);

    std::cout << "Trying to add via addNumbers (ok case): " << std::endl;
    sp.addNumbers(mirror.begin(), mirror.end());
    std::cout << "  " << sp << std::endl;

    std::cout << "Trying to add big vector via addNumbers: " << std::endl;
    try {
      sp2.addNumbers(big.begin(), big.end());
    }
    catch (std::exception const& e) {
      std::cout << "  " << e.what() << std::endl;
    }

    std::cout << "Trying to add via addNumbers (errorneous iterators): " << std::endl;
    try {
      sp2.addNumbers(big.end(), big.begin());
    }
    catch (std::exception const& e) {
      std::cout << "  " << e.what() << std::endl;
    }
  }

  {
    int const imin = std::numeric_limits<int>::min();
    int const imax = std::numeric_limits<int>::max();

    std::cout << "Testing shortest / longest span (base): " << std::endl;
    Span sp(5);
    for (Span::size_type i = 0; i < sp.capacity(); ++i) {
      sp.addNumber(rand() % 10);
    } 
    std::cout << " " << sp << std::endl;  
    std::cout << " shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << " longest span: " << sp.longestSpan() << std::endl;


    std::cout << "Testing shortest / longest span (very big): " << std::endl;
    Span sp2(100000000);
    std::vector<int> sp2mirror(100000000);

    for (std::vector<int>::iterator it = sp2mirror.begin(); it != sp2mirror.end(); ++it) {
      *it = std::rand() % imax + imin;
    }
    sp2.addNumbers(sp2mirror.begin(), sp2mirror.end());

    std::cout << " min: " << *std::min_element(sp2.begin(), sp2.end()) << std::endl;
    std::cout << " max: " << *std::max_element(sp2.begin(), sp2.end()) << std::endl;
    std::cout << " shortest span: " << sp2.shortestSpan() << std::endl;
    std::cout << " longest span: " << sp2.longestSpan() << std::endl;

  }

  
  /* { */
  /*   Span sp = Span(5); */
  /*   sp.addNumber(5); */
  /*   sp.addNumber(3); */
  /*   sp.addNumber(17); */
  /*   sp.addNumber(9); */
  /*   sp.addNumber(11); */

  /*   std::cout << sp.shortestSpan() << std::endl; */
  /*   std::cout << sp.longestSpan() << std::endl; */
  /* } */
  return (0);
}
