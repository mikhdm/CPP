/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 00:18:05 by rmander           #+#    #+#             */
/*   Updated: 2021/12/20 21:34:59 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <cstdlib>
#include <iostream>


int main(void) {

  Fixed a;

  Fixed const b(Fixed(5.05f));
  std::cout << b << std::endl;

  /* Fixed a; */
  /* Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) ); */
  /* std::cout << a << std::endl; */
  /* std::cout << ++a << std::endl; */
  /* std::cout << a << std::endl; */
  /* std::cout << a++ << std::endl; */
  /* std::cout << a << std::endl; */
  /* std::cout << b << std::endl; */
  /* std::cout << Fixed::max( a, b ) << std::endl; */
  return (EXIT_SUCCESS);
}

