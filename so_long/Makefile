# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/27 14:55:09 by lvan-slu          #+#    #+#              #
#    Updated: 2024/03/27 14:55:14 by lvan-slu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT :
SRCDIR = src libft
SRCS = $(wildcard $(addsuffix /*.c,$(SRCDIR)))
MLX = MacroLibX/libmlx.so -lSDL2
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra
EXEC = so_long
NAME = $(EXEC)

$(NAME): $(OBJS)
	$(MAKE) -C MacroLibX/ -s
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS) $(MLX) -I./libft

all: $(NAME)

clean:
	@rm -f $(OBJS)
	$(MAKE) clean -C MacroLibX/ -s

fclean: clean
	@rm -f $(NAME)
	$(MAKE) fclean -C MacroLibX/ -s

re: fclean all

.PHONY: all clean fclean re
