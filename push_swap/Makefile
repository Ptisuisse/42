# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 14:40:56 by lvan-slu          #+#    #+#              #
#    Updated: 2024/07/15 14:40:57 by lvan-slu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.c \
		parsing.c \
		lst_utils.c \
		move.c \
		sort.c \

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
EXEC = push_swap
NAME = $(EXEC)

$(NAME): $(OBJS)
	$(MAKE) -j -C libft/ -s
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS) -Llibft -lft -I./libft

all: $(NAME)

libft/libft.a:
	$(MAKE) -C libft/ -s

clean:
	@rm -f $(OBJS)
	$(MAKE) clean -C libft/ -s

fclean: clean
	@rm -f $(NAME)
	$(MAKE) fclean -C libft/ -s

re: fclean all

.PHONY: all bonus clean fclean re
