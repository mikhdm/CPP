/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 04:06:18 by rmander           #+#    #+#             */
/*   Updated: 2022/01/10 23:16:02 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include <string>


class ShrubberyCreationForm : public AForm {
 public:
  explicit ShrubberyCreationForm(void);
  explicit ShrubberyCreationForm(std::string const& target);
  ShrubberyCreationForm(ShrubberyCreationForm const& instance);
  virtual ~ShrubberyCreationForm(void);
  ShrubberyCreationForm& operator=(ShrubberyCreationForm const& instance);

  std::string const& getTarget(void) const;
  void execute(Bureaucrat const& executor) const;
 private:
  void makeTree(void) const;
  std::string _target;
};


# endif
