CC=gcc
CFLAGS= -Werror -Wextra -Wall
SRC= ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memset.c ft_strlen.c ft_tolower.c ft_toupper.c
OBJ= $(SRC:.c=.o)
NAME=libft.a

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME) : $(OBJ)
	ar rsc $(NAME) $(SRC)

clean :
	rm -rf *.o

fclean : clean
	rm -f $(NAME)

re : clean
	rm -f $(NAME)

.PHONY: clean mrproper

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ)
