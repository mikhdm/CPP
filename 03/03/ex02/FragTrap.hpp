/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:12:54 by rmander           #+#    #+#             */
/*   Updated: 2021/12/22 12:29:55 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "ClapTrap.hpp"


class FragTrap : public ClapTrap {
 public:
  FragTrap(std::string const& name);
  FragTrap(FragTrap const& instance);
  virtual ~FragTrap(void);
  FragTrap& operator=(FragTrap const& instance);

  void attack(std::string const& target);
  void highFivesGuys(void);

 private:
  FragTrap(void);

};


#endif // FRAGTRAP_H
