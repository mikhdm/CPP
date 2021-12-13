# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 03:21:15 by rmander           #+#    #+#              #
#    Updated: 2021/12/13 22:10:39 by rmander          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

CC = clang++
CPPFLAGS = -fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer -g3 -O0 -std=c++98 -MMD -Wall -Wextra -Werror

SRCS = ./Contact.cpp \
	   ./PhoneBook.cpp \
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
