# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 14:52:06 by rmander           #+#    #+#              #
#    Updated: 2021/12/17 21:22:56 by rmander          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombie

CC = clang++
CPPFLAGS = -std=c++98 -MD -Wall -Wextra -Werror -Wpedantic

SRCS = ./Zombie.cpp \
	   ./ZombieHorde.cpp \
	   ./main.cpp

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

