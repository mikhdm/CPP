/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 02:54:58 by rmander           #+#    #+#             */
/*   Updated: 2022/01/10 23:17:27 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef FORM_HPP
# define FORM_HPP

#include <string>

#include "Bureaucrat.hpp"


class AForm {
 public:
  explicit AForm(void);
  AForm(AForm const& instance); 
  virtual ~AForm(void);
  AForm& operator=(AForm const& instance);
  explicit AForm(std::string const& name,
      unsigned int signGrade, unsigned execGrade);

  std::string const& getName(void) const;
  bool getSigned(void) const;
  unsigned int getSignGrade(void) const;
  unsigned int getExecGrade(void) const;

  void beSigned(Bureaucrat const& b);
  virtual void execute(Bureaucrat const& executor) const = 0;

  class GradeTooHighException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

  class ExecutionForbiddenException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

 protected:
  explicit AForm(std::string const& name,
      unsigned int signGrade, unsigned execGrade, bool isSigned);

 private:
  static unsigned int const kGradeMax;
  static unsigned int const kGradeMin;

  std::string const _name;
  unsigned int const _signGrade;
  unsigned int const _execGrade;
  bool _signed;
};

std::ostream& operator<<(std::ostream& o, AForm const& f);

# endif
