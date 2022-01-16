/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 05:06:45 by rmander           #+#    #+#             */
/*   Updated: 2022/01/16 07:00:38 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
 public:
  typedef typename std::stack<T>::container_type::iterator iterator;
  typedef typename std::stack<T>::container_type::const_iterator const_iterator;

  MutantStack<T>(void);
  virtual ~MutantStack<T>(void);
  MutantStack<T>(MutantStack<T> const& instance);
  MutantStack<T>& operator=(MutantStack<T> const& instance); 

  iterator begin(void);
  iterator end(void);
  const_iterator begin(void) const;
  const_iterator end(void) const;
};


template <typename T>
MutantStack<T>::MutantStack(void) : std::stack<T>() {}


template <typename T>
MutantStack<T>::~MutantStack(void) {}


template <typename T>
MutantStack<T>::MutantStack(MutantStack<T> const& s) : std::stack<T>(s) {}


template <typename T>
MutantStack<T>& MutantStack<T>::operator=(MutantStack<T> const& s) {
  if (this == &s) {
    return *this;
  }
  this->c = s.c;
  return *this;
}


template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void) {
  return this->c.begin();
} 


template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin(void) const {
  return this->c.begin();
} 


template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void) {
  return this->c.end();
} 


template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end(void) const {
  return this->c.end();
} 


# endif
