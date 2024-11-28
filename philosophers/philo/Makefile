# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/28 11:53:47 by lvan-slu          #+#    #+#              #
#    Updated: 2024/11/28 11:53:48 by lvan-slu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.c \
		init_struct.c \
		philo.c \
		utils.c \
		ft_supervisor.c \
		time_and_print.c \

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
EXEC = philo
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
