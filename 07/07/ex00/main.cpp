/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:00:26 by rmander           #+#    #+#             */
/*   Updated: 2022/01/14 18:04:49 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <iomanip>

#include "whatever.hpp"

// special for this test only
std::ostream& operator<<(std::ostream& o, std::vector<int> const& v) {
    o << v[0];
    return o;
}


template <typename T>
void test(T& lhs, T& rhs) {
    std::cout << "swap: " << std::endl; 
    std::cout << "  before: "
        <<  "(" << lhs << ", " << rhs << ")" << std::endl;

    ::swap(lhs, rhs);
    std::cout << "  after:  "
        <<  "(" << lhs << ", " << rhs << ")" << std::endl << std::endl;
}


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


template <typename T>
void test(T const& lhs, T const& rhs, std::string const& ty) {
    std::cout << "lhs: " << lhs <<", rhs = " << rhs << std::endl; 
    if (ty == "min")
        std::cout << "min( lhs, rhs ) = " << ::min( lhs, rhs ) << std::endl;
    if (ty == "max")
        std::cout << "max( lhs, rhs ) = " << ::max( lhs, rhs ) << std::endl;
}


int main(void) {
    int il = 1;
    int ir = 2;

    float fl = 1.0;
    float fr = 2.0;

    std::vector<int> vl;
    vl.push_back(1000);

    std::vector<int> vr;
    vr.push_back(2000);

    test<int>(il, ir);
    test<float>(fl, fr);
    test< std::vector<int> >(vl, vr);
    
    test(il, ir, "min"); 
    test(fl, fr, "max"); 

    std::cout << "Subject: " << std::endl;
    {
        int a = 2;
        int b = 3;
        ::swap( a, b );
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
        std::string c = "chaine1";
        std::string d = "chaine2";
        ::swap(c, d);
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
        std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    }
    return (0);
}

