/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:19:27 by rmander           #+#    #+#             */
/*   Updated: 2022/01/14 19:14:41 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ITER_HPP
# define ITER_HPP

#include <cstdlib>
#include <iostream>


template <typename T>
void iter(T* arr, size_t const sz, void (*func)(T const&)) {
    if (!arr || !func) {
        return ;
    }
    for (size_t i = 0; i < sz; ++i) {
        func(arr[i]);
    }
} 


// helper function to test

template <typename T>
void sq(T const& v) {
    std::cout << v * v << std::endl;
}


template <typename T>
void show(T const& v) {
    std::cout << v << std::endl;
}


#endif
