# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/10 16:37:19 by lvan-slu          #+#    #+#              #
#    Updated: 2024/12/10 16:37:20 by lvan-slu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	megaphone.cpp \

OBJS = $(SRCS:.cpp=.o)
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
EXEC = megaphone
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