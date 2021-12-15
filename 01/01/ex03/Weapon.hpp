/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:02:47 by rmander           #+#    #+#             */
/*   Updated: 2021/12/15 18:18:50 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# include <string>


class Weapon {
 public:
   Weapon(void);
   Weapon(std::string const& ty);
   ~Weapon(void);

   std::string const& getType(void) const;
   void setType(std::string const& ty);
 private:
  std::string type;
};


#endif

