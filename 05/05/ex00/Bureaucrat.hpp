/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 20:53:55 by rmander           #+#    #+#             */
/*   Updated: 2022/01/08 22:30:36 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>


class Bureaucrat {
 public:
  Bureaucrat(void);
  ~Bureaucrat(void);
  Bureaucrat(Bureaucrat const& instance);
  Bureaucrat& operator=(Bureaucrat const& instance);
  Bureaucrat(unsigned int grade);

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


#endif
