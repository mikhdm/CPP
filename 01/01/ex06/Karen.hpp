/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:31:29 by rmander           #+#    #+#             */
/*   Updated: 2021/12/17 21:08:09 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_H
# define KAREN_H

# include <string>

# define SH_COLOR_WHITE		"\033[37m"
# define SH_COLOR_BLUE		"\033[34m"
# define SH_COLOR_PURPLE	"\033[35m"
# define SH_COLOR_RED			"\033[31m"
# define SH_COLOR_YELLOW	"\033[33m"
# define SH_COLOR_GREEN		"\033[32m"
# define SH_COLOR_RESET		"\033[m"
# define SH_COLOR_BOLD		"\033[1m"

enum KarenLevel {
  kLevelDebug = 0,
  kLevelInfo ,
  kLevelWarning,
  kLevelError,
  kLevelUnknown
}; 

class Karen {
 public:
  Karen(std::string level);
  ~Karen(void);

  void complain(std::string level);
  void unknown(void);
  KarenLevel getLevel(void) const;
  void setLevel(std::string lvl);

 private:
  Karen(void);
  size_t index(std::string level) const;
  void debug(void);
  void info(void);
  void warning(void);
  void error(void);
  KarenLevel level(std::string level) const;
  KarenLevel _level;
};


#endif // KAREN_H
