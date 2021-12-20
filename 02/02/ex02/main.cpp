/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 00:18:05 by rmander           #+#    #+#             */
/*   Updated: 2021/12/20 22:30:16 by rmander          ###   ########.fr       */
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
	std::cout << "Fixed:      " << std::setw(12)
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
	/* compareDivision(999999, 1000000); */
	/* compareDivision(7777777, 8000000); */
	compareDivision(1, 1);
	compareDivision(3, 2);
	compareDivision(6, 2);

	/* compareMultiplication(7777777, 0.5f); */
	/* compareMultiplication(7777777, 0.3f); */
}

int 	main( int argc, char** )
{
  (void) argc;
		test();
		return 0;
}
