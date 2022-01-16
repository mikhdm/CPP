/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:40:03 by rmander           #+#    #+#             */
/*   Updated: 2022/01/16 15:14:07 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>


template <typename T>
typename T::iterator easyfind(T& container, int value) {
  typename T::iterator it = 
    std::find(container.begin(), container.end(), value);
  return it;
}


template <typename T>
typename T::const_iterator easyfind(T const& container, int value) {
  typename T::const_iterator it = 
    std::find(container.begin(), container.end(), value);
  return it;
}


#endif
