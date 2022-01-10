/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 23:20:21 by rmander           #+#    #+#             */
/*   Updated: 2022/01/11 00:44:02 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp" 


class Intern {
 public:
  explicit Intern(void);
  Intern(Intern const& instance);
  virtual ~Intern(void);
  Intern& operator=(Intern const& instance);

  AForm* makeForm(std::string const& name, std::string const& target);
  size_t indexOf(std::string const* names, std::string const& name);

  class OutOfRangeException : public std::exception {
   public:
     virtual const char* what() const throw();
  };

 private:
  AForm* shrubbery(std::string const& target);
  AForm* presidential(std::string const& target);
  AForm* robotomy(std::string const& target);
  static const size_t kFormsCount;
};


#endif
