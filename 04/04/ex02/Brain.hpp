/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 01:00:28 by rmander           #+#    #+#             */
/*   Updated: 2022/01/06 01:52:24 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string> 

# define IDEAS_COUNT 100


class Brain {
 public:
   Brain(void);
   Brain(Brain const& instance);
   virtual ~Brain(void);
   Brain& operator=(Brain const& instance);

   std::string const& getIdea(unsigned int n) const;
   void setIdea(unsigned int n, std::string idea);
 private:
   std::string ideas[IDEAS_COUNT];
};

#endif // BRAIN_HPP
