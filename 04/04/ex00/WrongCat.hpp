/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 21:03:35 by rmander           #+#    #+#             */
/*   Updated: 2022/01/06 00:13:29 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"


class WrongCat : public WrongAnimal {
 public:
   WrongCat(void);
   WrongCat(WrongCat const& instance);
   virtual ~WrongCat(void);
   WrongCat& operator=(WrongCat const& instance);
   void makeSound(void) const;
};

#endif // WRONGCAT_HPP
