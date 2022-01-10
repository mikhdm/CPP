/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 04:06:18 by rmander           #+#    #+#             */
/*   Updated: 2022/01/10 04:34:58 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

#include <string>


class ShrubberyCreationForm : public Form {
 public:
  explicit ShrubberyCreationForm(void);
  explicit ShrubberyCreationForm(std::string const& target);
  explicit ShrubberyCreationForm(ShrubberyCreationForm const& instance);
  virtual ~ShrubberyCreationForm(void);
  ShrubberyCreationForm& operator=(ShrubberyCreationForm const& instance);
 private:
  void makeTree(std::string const& target);
};


# endif
