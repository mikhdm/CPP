/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:23:10 by rmander           #+#    #+#             */
/*   Updated: 2021/12/15 18:11:10 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H 

# include "Weapon.hpp"


class HumanB {
 public:
  HumanB(std::string const& name);
  ~HumanB(void);

  void attack(void) const;
  void setWeapon(Weapon const& weapon);
  Weapon const* getWeapon(void) const;
 private:
  std::string _name;
  Weapon const* _weapon;
};


#endif

