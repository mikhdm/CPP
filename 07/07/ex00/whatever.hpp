/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:00:47 by rmander           #+#    #+#             */
/*   Updated: 2022/01/14 18:05:10 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

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


# endif
