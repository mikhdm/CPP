# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 19:03:35 by rmander           #+#    #+#              #
#    Updated: 2021/12/16 19:11:40 by rmander          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = replace

CC = clang++
CPPFLAGS = -std=c++98 -MD -Wall -Wextra -Werror

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

test: all
	@./tests/run

re: fclean all

.PHONY: all clean fclean re test
