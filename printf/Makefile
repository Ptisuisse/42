SRCS =  ft_printf

CC = cc

CFLAGS = -Wall -Werror -Wextra

EXEC = libftprintf.a

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
