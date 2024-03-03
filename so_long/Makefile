SRCDIR = map libft

SRCS = map.c \
       $(wildcard libft/*.c) \

CC = gcc
CFLAGS = -Wall -Werror -Wextra
EXEC = so_long.a
OBJ = $(SRCS:.c=.o) $(SRCDIR)
NAME = $(EXEC)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -c $(SRCS) -I./
	ar -rc $(EXEC) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
