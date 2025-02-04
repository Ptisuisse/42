# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/15 12:23:34 by lvan-slu          #+#    #+#              #
#    Updated: 2025/01/15 12:23:36 by lvan-slu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.cpp \
		Weapon.cpp \
		HumanA.cpp \
		HumanB.cpp \

OBJS = $(SRCS:.cpp=.o)
CC = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
EXEC = violence
NAME = $(EXEC)

$(NAME): $(OBJS)
	$(CC) -o $(EXEC) $(OBJS)

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all, clean, fclean, re
