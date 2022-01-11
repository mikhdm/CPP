/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 22:39:31 by rmander           #+#    #+#             */
/*   Updated: 2022/01/11 15:46:56 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include <string>


class PresidentialPardonForm : public AForm {
 public:
  explicit PresidentialPardonForm(void);
  explicit PresidentialPardonForm(std::string const& target);
  PresidentialPardonForm(PresidentialPardonForm const& instance);
  virtual ~PresidentialPardonForm(void);
  PresidentialPardonForm& operator=(PresidentialPardonForm const& instance);

  std::string const& getTarget(void) const;
  void execute(Bureaucrat const& executor) const;

 private:
  std::string _target;
};


#endif
