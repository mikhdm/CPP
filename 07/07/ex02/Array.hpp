/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:16:34 by rmander           #+#    #+#             */
/*   Updated: 2022/01/14 23:05:24 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>

template <typename T>
class Array {
 public:
  explicit Array<T>(void);
  explicit Array<T>(unsigned int n);
  ~Array<T>(void);
  Array<T>(Array<T> const& instance);
  Array<T>& operator=(Array<T> const& instance);

  T& operator[](unsigned int i);

  unsigned int size(void) const; 
 private:
  unsigned int _size;
  T* _data;
};


template <typename T>
Array<T>::Array(void) : _size(0), _data(new T[0]) {}


// C++03 allowed value initialization 
// via call new T[N]() <- braces add default values instead of garbage values
template <typename T>
Array<T>::Array(unsigned int n) : _size(n), _data(new T[n]) {
  for (unsigned int i = 0; i < n; ++i) {
    _data[i] = 0;
  } 
}


template <typename T>
Array<T>::~Array(void) {
  delete [] _data;
}


template <typename T>
Array<T>::Array(Array<T> const& instance) :
  _size(instance.size()), _data(new T[instance.size()]) {
  for (unsigned int i = 0; i < _size; ++i) {
    _data[i] = instance[i];
  }
}


template <typename T>
Array<T>& Array<T>::operator=(Array<T> const& instance) {
  if (this == &instance) {
    return *this;
  }

  for (unsigned int i = 0; i < instance.size(); ++i) {

  }
}


template <typename T>
T& Array<T>::operator[](unsigned int i) {
  if (i >= _size)
    throw std::exception();
  return _data[i];
}

# endif
