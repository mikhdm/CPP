# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/16 05:05:50 by rmander           #+#    #+#              #
#    Updated: 2022/01/16 06:31:11 by rmander          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mutantstack

CC = clang++
CPPFLAGS = -std=c++98 -MD -Wall -Wextra -Werror -Wpedantic -Wshadow -Wc++98-compat-pedantic

SRCS = ./main.cpp \
	   ./mutantstack.cpp

OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

all: $(NAME)

-include $(DEPS)

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) -I . $^ -o $@

%.o: %.cpp
	$(CC) $(CPPFLAGS) -I . -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
