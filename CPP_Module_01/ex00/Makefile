# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/15 10:18:50 by lvan-slu          #+#    #+#              #
#    Updated: 2025/01/15 10:18:53 by lvan-slu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.cpp \
		Zombie.cpp \
		newZombie.cpp \
		randomChump.cpp \

OBJS = $(SRCS:.cpp=.o)
CC = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
EXEC = zombie
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
