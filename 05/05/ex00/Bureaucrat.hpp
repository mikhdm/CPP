/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 20:53:55 by rmander           #+#    #+#             */
/*   Updated: 2022/01/08 23:05:58 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>


class Bureaucrat {
 public:
  Bureaucrat(void);
  virtual ~Bureaucrat(void);
  Bureaucrat(Bureaucrat const& instance);
  Bureaucrat(std::string const& name, unsigned int grade);
  Bureaucrat& operator=(Bureaucrat const& instance);

  std::string const& getName(void) const;
  unsigned int getGrade(void) const;
  void incGrade(void);
  void decGrade(void);

  class GradeTooHighException : public std::exception {
   public:
    virtual const char* what() const;
  }

  class GradeTooLowException : public std::exception {
   public:
    virtual const char* what() const;
  }

 private:
  static unsigned int gradeMax;
  static unsigned int gradeMin;
  std::string const _name;
  unsigned int _grade;
};

std::ostream& operator<<(std::ostream const& o, Bureaucrat const& b);

#endif
