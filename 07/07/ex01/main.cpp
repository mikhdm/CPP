/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:19:49 by rmander           #+#    #+#             */
/*   Updated: 2022/01/14 19:15:41 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>


int main(void) {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    iter<int>(a, 8, &sq);
    
    std::cout << std::endl;
    std::string b[] = {"hai", "hoi", "hei"};
    iter(b, 3, &show);
    
    iter<std::nullptr_t>(nullptr, 10, &show);
    iter<std::nullptr_t>(nullptr, 10, nullptr);
    iter<std::nullptr_t>(nullptr, -1, nullptr);

    return (0);
}
