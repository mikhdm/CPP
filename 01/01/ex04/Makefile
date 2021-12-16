# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 19:03:35 by rmander           #+#    #+#              #
#    Updated: 2021/12/16 18:51:07 by rmander          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = replace

CC = clang++
CPPFLAGS = -std=c++98 -MD -fsanitize=address -fsanitize=undefined -Wall -Wextra -Werror

SRCS = ./main.cpp

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
	rm -f tests/*.replace

fclean: clean
	rm -f $(NAME)

test:

re: fclean all

.PHONY: all clean fclean re
