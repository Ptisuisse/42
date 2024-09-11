SRCS =	main.c \
		error.c \
		init_struct.c \
		time.c \
		philo.c \

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
EXEC = philo
NAME = $(EXEC)

$(NAME): $(OBJS)
	$(MAKE) -j -C libft/ -s
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS) -Llibft -lft -I./libft

all : $(NAME)

clean :
	rm -f $(OBJS)
	$(MAKE) clean -C libft/ -s

fclean : clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft/ -s

re : fclean all

.PHONY : all, clean, fclean, re
