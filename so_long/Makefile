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
SRCS =	src/errors.c \
		src/events.c \
		src/flood_fill.c \
		src/free.c \
		src/images.c \
		src/init.c \
		src/main.c \
		src/map.c \
		src/mlx.c \
		src/move.c \

SRCSB = src_bonus/errors.c \
		src_bonus/events.c \
		src_bonus/flood_fill.c \
		src_bonus/free.c \
		src_bonus/images.c \
		src_bonus/init.c \
		src_bonus/main.c \
		src_bonus/map.c \
		src_bonus/mlx.c \
		src_bonus/move.c \
		src_bonus/bonus.c \

MLX = MacroLibX/libmlx.so -lSDL2
OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCSB:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra
EXEC = so_long
EXECB = so_long_bonus
NAME = $(EXEC)
NAMEB = $(EXECB)

$(NAME): $(OBJS)
	$(MAKE) -j -C MacroLibX/ -s
	$(MAKE) -j -C libft/ -s
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS) $(MLX) -Llibft -lft -I./libft

$(NAMEB): $(OBJSB)
	$(MAKE) -j -C MacroLibX/ -s
	$(CC) $(CFLAGS) -o $(EXECB) $(OBJSB) $(MLX) -Llibft -lft -I./libft

all: $(NAME)

bonus: $(NAMEB)
	@rm -f $(OBJS)
	@rm -f $(NAME)

libft/libft.a:
	$(MAKE) -C libft/ -s

clean:
	@rm -f $(OBJS) $(OBJSB)
	$(MAKE) clean -C MacroLibX/ -s
	$(MAKE) clean -C libft/ -s

fclean: clean
	@rm -f $(NAME) $(NAMEB)
	$(MAKE) fclean -C MacroLibX/ -s
	$(MAKE) fclean -C libft/ -s

re: fclean all

.PHONY: all bonus clean fclean re
