# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/13 18:23:42 by rmander           #+#    #+#              #
#    Updated: 2022/01/13 18:24:06 by rmander          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = serialize

CC = clang++
CPPFLAGS = -std=c++98 -MD -Wall -Wextra -Werror -Wpedantic -Wconversion -Wsign-conversion -Wshadow -Wc++98-compat-pedantic

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

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
