/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:00:47 by rmander           #+#    #+#             */
/*   Updated: 2022/01/15 20:51:21 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>
#include <iomanip>

// function templates 

template <typename T>
void swap(T& lhs, T& rhs) {
    T tmp(lhs);
    lhs = rhs;
    rhs = tmp;
}


template <typename T>
T const& min(T const& lhs, T const& rhs) {
    return (lhs < rhs) ? lhs : rhs; 
}


template <typename T>
T const& max(T const& lhs, T const& rhs) {
    return (lhs > rhs) ? lhs : rhs; 
}


// helper function templates & overloads

std::ostream& operator<<(std::ostream& o, std::vector<int> const& v);

//
// test generic template

template <typename T>
void test(T& lhs, T& rhs) {
    std::cout << "swap: " << std::endl; 
    std::cout << "  before: "
        <<  "(" << lhs << ", " << rhs << ")" << std::endl;

    ::swap(lhs, rhs);

    std::cout << "  after:  "
        <<  "(" << lhs << ", " << rhs << ")" << std::endl << std::endl;
}


// test float specialization template

template <>
void test<float>(float& lhs, float& rhs) {
    std::cout << "swap: " << std::endl; 
    std::cout << "  before: "
        <<  "(" << std::fixed << std::setprecision(1)
        << lhs << ", " << rhs << ")" << std::endl;

    ::swap(lhs, rhs);

    std::cout << "  after:  "
        <<  "(" << std::fixed << std::setprecision(1)
        << lhs << ", " << rhs << ")" << std::endl << std::endl;
}


// test T const specialization

template <typename T>
void test(T const& lhs, T const& rhs, std::string const& ty) {
    std::cout << "lhs: " << lhs <<", rhs = " << rhs << std::endl; 
    if (ty == "min")
        std::cout << "min( lhs, rhs ) = " << ::min( lhs, rhs ) << std::endl;
    if (ty == "max")
        std::cout << "max( lhs, rhs ) = " << ::max( lhs, rhs ) << std::endl;
}


# endif
