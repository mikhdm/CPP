/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 00:18:05 by rmander           #+#    #+#             */
/*   Updated: 2021/12/20 23:28:52 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <cstdlib>
#include <iostream>
#include <iomanip>


void	compareDivision(Fixed x, Fixed y)
{
	std::cout << std::setprecision(30);
	std::cout << "Fixed:     " << std::setw(12)
	          << x << " / " << y << " = " << x / y << std::endl;
	std::cout << "toFloat(): " << std::setw(12)
	          << x.toFloat() << " / " << y.toFloat()
	          << " = " << x.toFloat() / y.toFloat() << std::endl;
	std::cout << std::endl;
}


void	compareMultiplication(Fixed fx, Fixed fy)
{
	std::cout << std::setprecision(30);
	std::cout << "Fixed:     " << std::setw(12)
	          << fx << " * " << fy << " = " << fx * fy << std::endl;

	std::cout << "toFloat(): " << std::setw(12)
	          << fx.toFloat() << " * " << fy.toFloat()
	          << " = " << fx.toFloat() * fy.toFloat() << std::endl;
	std::cout << std::endl;
}


void	test()
{
	Fixed	x(1), y(128);

	compareDivision(x, y);
	x.setRawBits(1);
	y.setRawBits(128);
	compareDivision(x, y);
	compareDivision(x, y);
	x.setRawBits(127);
	y.setRawBits(128);
	compareDivision(127, 128);
	compareDivision(999999, 1000000);
	compareDivision(7777777, 8000000);
	compareDivision(1, 1);
	compareDivision(3, 2);
	compareDivision(6, 2);

	std::cout << "max("<<x<< ","<<y<<") = "<<Fixed::max(x, y) << std::endl;
	std::cout << "min("<<x<< ","<<y<<") = "<<Fixed::min(x, y) << std::endl;

	compareMultiplication(7777777, 0.5f);
	compareMultiplication(7777777, 0.3f);
}

int 	main(int argc, char** argv)
{

	(void) argc;
	(void) argv;
	/* { */
	/* 	test(); */
	/* } */
	
	/* std::cout << SH_COLOR_BOLD */
	/* 	<< SH_COLOR_YELLOW << "SUBJECT:" << SH_COLOR_RESET */ 
	/* 	<<std::endl << std::endl; */

	/* { */
	/* 	Fixed a; */
	/* 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) ); */
	/* 	std::cout << a << std::endl; */
	/* 	std::cout << ++a << std::endl; */
	/* 	std::cout << a << std::endl; */
	/* 	std::cout << a++ << std::endl; */
	/* 	std::cout << a << std::endl; */
	/* 	std::cout << b << std::endl; */
	/* 	std::cout << Fixed::max(a, b) << std::endl; */
	/* } */
	
	std::cout << Fixed(7777777) * Fixed(0.5f) << std::endl;


	return 0;
}
