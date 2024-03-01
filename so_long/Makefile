SRCS =  map \
		get_next_line \
		get_next_line_utils \

CC = gcc

CFLAGS = -Wall -Werror -Wextra

EXEC = so_long.a

CFILES = $(SRCS:%=%.c)

OBJ = $(SRCS:=.o)

NAME = $(EXEC)

$(NAME):
	$(CC) $(CFLAGS) -c $(CFILES) -I./
	ar -rc $(EXEC) $(OBJ)

all : $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all, clean, fclean, re
