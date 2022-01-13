/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:30:35 by rmander           #+#    #+#             */
/*   Updated: 2022/01/13 19:39:27 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"


uintptr_t serialize(Data* ptr) {
  return reinterpret_cast<uintptr_t>(ptr);
}


Data*     deserialize(uintptr_t raw) {
  return reinterpret_cast<Data*>(raw);
}
