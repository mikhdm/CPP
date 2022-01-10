/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 20:53:55 by rmander           #+#    #+#             */
/*   Updated: 2022/01/10 22:59:22 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>


class Bureaucrat {
 public:
  explicit Bureaucrat(void);
  virtual ~Bureaucrat(void);
  Bureaucrat(Bureaucrat const& instance);
  explicit Bureaucrat(std::string const& name, unsigned int grade);
  Bureaucrat& operator=(Bureaucrat const& instance);

  std::string const& getName(void) const;
  unsigned int getGrade(void) const;
  void incGrade(void);
  void decGrade(void);

  class GradeTooHighException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

  class OpOverloadException : public std::exception {
   public:
    explicit OpOverloadException(std::string const& message);
    ~OpOverloadException(void) throw();
    const char* what() const throw();
   private:
    std::string _message;
  };

 private:
  static unsigned int const kGradeMax;
  static unsigned int const kGradeMin;
  std::string const   _name;
  unsigned int        _grade;
};

std::ostream& operator<<(std::ostream& o, Bureaucrat const& b);

#endif
