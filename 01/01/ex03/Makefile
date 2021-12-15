# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 15:58:49 by rmander           #+#    #+#              #
#    Updated: 2021/12/15 18:21:39 by rmander          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = human

CC = clang++
CPPFLAGS = -std=c++98 -MD -Wall -Wextra -Werror

SRCS = ./main.cpp \
	   ./HumanA.cpp \
	   ./HumanB.cpp \
	   ./Weapon.cpp

OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

all: $(NAME)

-include $(DEPS)

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) -I. $^ -o $@

%.o: %.cpp
	$(CC) $(CPPFLAGS) -I. -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
