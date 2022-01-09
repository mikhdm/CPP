/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 00:18:05 by rmander           #+#    #+#             */
/*   Updated: 2022/01/09 21:10:49 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <cstdlib>
#include <iostream>
#include <iomanip>


void	compareDiv(Fixed x, Fixed y) {
	std::cout << std::setprecision(30);
	std::cout << "Fixed:      " << std::setw(12)
	          << x << " / " << y << " = " << x / y << std::endl;
	std::cout << ".toFloat(): " << std::setw(12)
	          << x.toFloat() << " / " << y.toFloat()
	          << " = " << x.toFloat() / y.toFloat() << std::endl;
	std::cout << std::endl;
}


void	compareMult(Fixed x, Fixed y) {
	std::cout << std::setprecision(30);
	std::cout << "Fixed:      " << std::setw(12)
	          << x << " * " << y
						<< " = "
						<< x * y << std::endl;

	std::cout << ".toFloat(): " << std::setw(12)
	          << x.toFloat() << " * " << y.toFloat()
	          << " = "
						<< x.toFloat() * y.toFloat() << std::endl;
	std::cout << std::endl;
}


void	compareAdd(Fixed x, Fixed y) {
	std::cout << std::setprecision(30);
	std::cout << "Fixed:      " << std::setw(12)
	          << x << " + " << y
						<< " = "
						<< x + y << std::endl;

	std::cout << ".toFloat(): " << std::setw(12)
	          << x.toFloat() << " + " << y.toFloat()
	          << " = "
						<< x.toFloat() + y.toFloat() << std::endl;
	std::cout << std::endl;
}

void compareSub(Fixed x, Fixed y) {
	std::cout << std::setprecision(30);
	std::cout << "Fixed:      " << std::setw(12)
	          << x << " - " << y
						<< " = "
						<< x - y << std::endl;

	std::cout << ".toFloat(): " << std::setw(12)
	          << x.toFloat() << " - " << y.toFloat()
	          << " = "
						<< x.toFloat() - y.toFloat() << std::endl;
	std::cout << std::endl;

}


int 	main(int argc, char** argv) {
	static_cast<void>(argc);
	static_cast<void>(argv);

	{
		Fixed	x(1), y(128);

		compareDiv(x, y);
		x.setRawBits(1);
		y.setRawBits(128);
		compareDiv(x, y);
		compareDiv(x, y);
		x.setRawBits(127);
		y.setRawBits(128);
		compareDiv(127, 128);
		compareDiv(999999, 1000000);
		compareDiv(7777777, 8000000);
		compareDiv(1, 1);
		compareDiv(3, 2);
		compareDiv(6, 2);

		std::cout << "max("<<x<< ", "<<y<<") = "<<Fixed::max(x, y) << std::endl;
		std::cout << "min("<<x<< ", "<<y<<") = "<<Fixed::min(x, y)
			<< std::endl << std::endl;

		std::cout << "1 == 1 ? "<< ((Fixed(1) == Fixed(1)) ? "Yes" : "No") << std::endl;
		std::cout << "1 < 2 ? "<< ((Fixed(1) < Fixed(2)) ? "Yes" : "No") << std::endl; 
		std::cout << "1 > 2 ? "<< ((Fixed(1) > Fixed(2)) ? "Yes" : "No") << std::endl; 
		std::cout << "3 > 2 ? "<< ((Fixed(3) > Fixed(2)) ? "Yes" : "No") << std::endl; 
		std::cout << "3 != 2 ? "<< ((Fixed(3) != Fixed(2)) ? "Yes" : "No") 
			<< std::endl << std::endl; 

		compareMult(7777777, 0.5f);
		compareMult(7777777, 0.3f);

		compareAdd(1, 2);
		compareAdd(8388606, 1);
		compareAdd(8388606, 0.5f);
		compareSub(1, 2);
		compareSub(FIXED_INT_MAX, FIXED_INT_MAX);
		compareSub(FIXED_INT_MIN, FIXED_INT_MIN);

	}

	std::cout << SH_COLOR_BOLD
		<< SH_COLOR_YELLOW << "SUBJECT:" << SH_COLOR_RESET 
		<<std::endl << std::endl;

	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max(a, b) << std::endl;
	}
	std::cout << Fixed(7777777) * Fixed(0.5f) << std::endl;

	return (EXIT_SUCCESS);
}
