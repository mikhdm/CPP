# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/18 02:53:11 by rmander           #+#    #+#              #
#    Updated: 2021/12/18 02:53:50 by rmander          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fixed

CC = clang++
CPPFLAGS = -std=c++98 -MD -Wall -Wextra -Werror -Wpedantic

SRCS = ./main.cpp \
	   ./Fixed.cpp

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

