/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 21:12:20 by rmander           #+#    #+#             */
/*   Updated: 2022/01/16 04:31:00 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <algorithm>
#include <iostream>


class Span {
 public:
  typedef std::vector<int>::const_iterator            const_iter_type;
  typedef std::vector<int>::size_type                 size_type; 
  typedef const_iter_type::difference_type            diff_type; 

  explicit Span(unsigned int n);
  Span(Span const& instance);
  virtual ~Span(void);
  Span& operator=(Span const& instance);
  
  void addNumber(int n);
  void addNumbers(const_iter_type l, const_iter_type r);
  long shortestSpan(void) const;
  long longestSpan(void) const;

  Span::size_type size(void) const;
  Span::size_type capacity(void) const;

  const_iter_type begin(void) const;
  const_iter_type end(void) const;

  class FullSpanException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

  class InsufficientDataException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

  class InconsistentInputException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

 private:
  Span(void);
  bool is_sorted(void) const;

  std::vector<int>  _data;
};


std::ostream& operator<<(std::ostream& o, Span const& s);
#endif
