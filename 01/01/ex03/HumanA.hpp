/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:11:11 by rmander           #+#    #+#             */
/*   Updated: 2021/12/15 16:53:21 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H 

# include "Weapon.hpp"


class HumanA {
 public:
  HumanA(std::string const& name, Weapon const& weapon);
  ~HumanA();

  void attack(void) const;
 private:
  std::string _name;
  Weapon const& _weapon;
};


#endif

