/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:23:33 by rmander           #+#    #+#             */
/*   Updated: 2022/01/13 19:40:05 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

#include <iostream>

int main(void) {
  Data data;
  data.s = "Hello";
  data.v = 10;
  data.f = 100.0f;
  data.d = 1000.0;
  data.vp = &data.v;

  Data* pdata = &data;
  
  std::cout << "Original data address: " << pdata << std::endl;
  std::cout << "Contains values: " << std::endl;
  std::cout << "  s (std::string) = " << pdata->s << std::endl; 
  std::cout << "  v (int) = " << *pdata->vp << std::endl; 
  std::cout << "  f (float) = " << std::fixed << pdata->f << std::endl; 
  std::cout << "  d (double) = " << std::fixed << pdata->d << std::endl; 
  std::cout << "  vp (int * (to v)) = " << pdata->vp << std::endl; 
  
  std::cout << std::endl << "Serialization..." << std::endl << std::endl;
  uintptr_t raw = serialize(pdata);

  std::cout << "raw (uintptr_t value) = " << raw << std::endl;

  std::cout << std::endl << "Deserialization..." << std::endl << std::endl;
  Data *rpdata = deserialize(raw);

  std::cout << "Contains values (after deserialization from raw): " << std::endl;
  std::cout << "  s (std::string) = " << rpdata->s << std::endl; 
  std::cout << "  v (int) = " << *rpdata->vp << std::endl; 
  std::cout << "  f (float) = " << std::fixed << rpdata->f << std::endl; 
  std::cout << "  d (double) = " << std::fixed << rpdata->d << std::endl; 
  std::cout << "  vp (int * (to v)) = " << rpdata->vp << std::endl; 

  std::cout << std::endl << "Serialization back to new raw (from deserialized)..." << std::endl << std::endl;
  uintptr_t rraw = serialize(rpdata);

  std::cout << "rraw (uintptr_t value) = " << rraw << std::endl;

  std::cout << std::endl << "Deserialization back..." << std::endl << std::endl;

  Data *rrpdata = deserialize(rraw);

  std::cout << "Contains values (after deserialization from rraw): " << std::endl;
  std::cout << "  s (std::string) = " << rrpdata->s << std::endl; 
  std::cout << "  v (int) = " << *rrpdata->vp << std::endl; 
  std::cout << "  f (float) = " << std::fixed << rrpdata->f << std::endl; 
  std::cout << "  d (double) = " << std::fixed << rrpdata->d << std::endl; 
  std::cout << "  vp (int * (to v)) = " << rrpdata->vp << std::endl; 

  return (EXIT_SUCCESS);
}
