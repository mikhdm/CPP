# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 01:03:49 by rmander           #+#    #+#              #
#    Updated: 2022/01/14 23:15:03 by rmander          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = aanimal

CC = clang++
CPPFLAGS = -std=c++98 -MD -Wall -Wextra -Werror -Wpedantic -Wshadow -Wc++98-compat-pedantic

SRCS = ./main.cpp \
			 ./AAnimal.cpp \
			 ./Cat.cpp \
			 ./Dog.cpp \
			 ./Brain.cpp

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
