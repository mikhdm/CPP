/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:44:29 by rmander           #+#    #+#             */
/*   Updated: 2022/01/06 00:13:44 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"


class Cat : public Animal {
 public:
   Cat(void);
   Cat(Cat const& instance);
   virtual ~Cat(void);
   Cat& operator=(Cat const& instance);
   void makeSound(void) const;
};

#endif // CAT_HPP
