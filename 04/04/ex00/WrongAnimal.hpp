/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:58:54 by rmander           #+#    #+#             */
/*   Updated: 2022/01/06 00:12:13 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>


class WrongAnimal {
 public:
  WrongAnimal(void);
  WrongAnimal(WrongAnimal const& instance);
  virtual ~WrongAnimal(void);
  WrongAnimal& operator=(WrongAnimal const& instance);

  std::string const& getType(void) const;
  void setType(std::string const& newType);
  void makeSound(void) const;
  static void log(std::string const& message, std::string const& color);
 protected:
  WrongAnimal(std::string const& ty);
  std::string type;
};

#endif // WRONGANIMAL_HPP
