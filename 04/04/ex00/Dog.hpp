/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:54:57 by rmander           #+#    #+#             */
/*   Updated: 2022/01/06 00:00:54 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"


class Dog : public Animal {
 public:
   Dog(void);
   Dog(Dog const& instance);
   virtual ~Dog(void);
   Dog& operator=(Dog const& instance);
   void makeSound(void) const;
};


#endif // DOG_HPP
