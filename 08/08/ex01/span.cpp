/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 21:39:28 by rmander           #+#    #+#             */
/*   Updated: 2022/01/16 20:07:04 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

#include <algorithm>


Span::Span(unsigned int n) {
  _data.reserve(n);
}


Span::~Span(void) {}


Span::Span(Span const& instance) {
  _data.reserve(instance.capacity());
  *this = instance;
}


Span& Span::operator=(Span const& instance) {
  if (this == &instance)
    return *this;
  if (_data.capacity() < instance.capacity())
    throw InconsistentInputException();
  addNumbers(instance.begin(), instance.end());
  return *this;
}


long Span::shortestSpan(void) const {
  if (_data.size() <= 1)
    throw InsufficientDataException();
  Span::const_iter_type ib = _data.begin();
  Span::const_iter_type ie = _data.end();
  long min = std::abs(static_cast<long>(*(ib + 1)) - static_cast<long>(*ib));
  long curr = min;
  for (Span::const_iter_type it = ib + 2; it != ie; ++it) {
    curr = std::abs(static_cast<long>(*it) - static_cast<long>(*(it - 1)));
    if (curr <= min) {
      min = curr;
    }
  }
  return min;
}


long Span::longestSpan(void) const {
  if (_data.size() <= 1)
    throw InsufficientDataException();
  long max = *std::max_element(begin(), end());
  long min = *std::min_element(begin(), end());
  return max - min; 
}


void Span::addNumber(int n) {
  if (_data.capacity() == _data.size())
    throw FullSpanException();
  _data.push_back(n);
 
  // invariant: _data is sorted
  std::sort(_data.begin(), _data.end());
}


void Span::addNumbers(Span::const_iter_type l, Span::const_iter_type r) {
  Span::diff_type isize = r - l;
  Span::size_type space = _data.capacity() - _data.size();

  if (isize < 0) {
    throw InconsistentInputException();
  }
  if (space < static_cast<Span::size_type>(isize)) {
    throw FullSpanException();
  }
  std::copy(l, r, std::back_inserter(_data));

  // invariant: _data is sorted
  std::sort(_data.begin(), _data.end());
}


Span::size_type Span::size(void) const {
  return _data.size();
}


Span::size_type Span::capacity(void) const {
  return _data.capacity();
}


Span::const_iter_type Span::begin(void) const {
  return _data.begin();
}


Span::const_iter_type Span::end(void) const {
  return _data.end();
}


std::ostream& operator<<(std::ostream& o, Span const& s) {
  for (Span::const_iter_type it = s.begin(); it != s.end(); ++it) {
    o << *it << " ";
  }
  return o;
}


const char* Span::FullSpanException::what() const throw() {
  return "Span is full.";
}


const char* Span::InsufficientDataException::what() const throw() {
  return "Data size is too small.";
}


const char* Span::InconsistentInputException::what() const throw() {
  return "Inconsistent input.";
}
