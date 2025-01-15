# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/15 18:00:58 by lvan-slu          #+#    #+#              #
#    Updated: 2025/01/15 18:00:59 by lvan-slu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.cpp \
		Harl.cpp \

OBJS = $(SRCS:.cpp=.o)
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
EXEC = harl
NAME = $(EXEC)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all, clean, fclean, re
