/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:58:07 by rmander           #+#    #+#             */
/*   Updated: 2022/01/10 23:15:08 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include <string>

class RobotomyRequestForm : public AForm {
 public:
  explicit RobotomyRequestForm(void);
  explicit RobotomyRequestForm(std::string const& target);
  RobotomyRequestForm(RobotomyRequestForm const& instance);
  virtual ~RobotomyRequestForm(void);
  RobotomyRequestForm& operator=(RobotomyRequestForm const& instance);

  std::string const& getTarget(void) const;
  void execute(Bureaucrat const& executor) const;

  class FailureException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

 private:
  void tellMessage(void) const;
  std::string _target;
};

#endif 
