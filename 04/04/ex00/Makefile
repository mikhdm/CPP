# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 01:03:49 by rmander           #+#    #+#              #
#    Updated: 2022/01/06 18:35:17 by rmander          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = animal

CC = clang++
CPPFLAGS = -std=c++98 -MD -Wall -Wextra -Werror -Wpedantic -Wshadow -Wc++98-compat-pedantic

SRCS = ./main.cpp \
			 ./Animal.cpp \
			 ./Cat.cpp \
			 ./Dog.cpp \
			 ./WrongAnimal.cpp \
			 ./WrongCat.cpp

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
