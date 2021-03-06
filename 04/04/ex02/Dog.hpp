/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:54:57 by rmander           #+#    #+#             */
/*   Updated: 2022/01/06 20:00:45 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"


class Dog : public AAnimal {
 public:
  Dog(void);
  Dog(Dog const& instance);
  virtual ~Dog(void);
  Dog& operator=(Dog const& instance);
  void makeSound(void) const;
  Brain* getBrain(void) const;
 private:
  Brain* brain;
};


#endif // DOG_HPP
