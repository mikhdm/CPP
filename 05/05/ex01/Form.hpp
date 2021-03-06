/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 02:54:58 by rmander           #+#    #+#             */
/*   Updated: 2022/01/10 22:59:00 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FORM_HPP
# define FORM_HPP

#include <string>

#include "Bureaucrat.hpp"


class Form {
 public:
  explicit Form(void);
  Form(Form const& instance); 
  virtual ~Form(void);
  Form& operator=(Form const& instance);
  explicit Form(std::string const& name,
      unsigned int signGrade, unsigned execGrade);

  std::string const& getName(void) const;
  bool getSigned(void) const;
  unsigned int getSignGrade(void) const;
  unsigned int getExecGrade(void) const;

  void beSigned(Bureaucrat const& b);

  class GradeTooHighException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

 private:
  static unsigned int const kGradeMax;
  static unsigned int const kGradeMin;

  std::string const _name;
  unsigned int const _signGrade;
  unsigned int const _execGrade;
  bool _signed;
};

std::ostream& operator<<(std::ostream& o, Form const& f);

# endif
