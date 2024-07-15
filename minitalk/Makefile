# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/14 16:07:14 by lvan-slu          #+#    #+#              #
#    Updated: 2024/07/14 16:07:18 by lvan-slu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC            = cc
CFLAGS        = -Wextra -Wall -Werror -g

SRCS_CLIENT        = client.c
OBJTS_CLIENT    = ${SRCS_CLIENT:.c=.o}
NAME_CLIENT        = client

SRCS_SERV    = server.c
OBJTS_SERV    = ${SRCS_SERV:.c=.o}
NAME_SERV    = server

LIBFT_DIRECTORY    = libft
LIB                = $(LIBFT_DIRECTORY)/libft.a

all: $(LIB) $(NAME_CLIENT) $(NAME_SERV)

$(LIB):
	@make -C $(LIBFT_DIRECTORY)

$(NAME_CLIENT): $(LIB) $(OBJTS_CLIENT)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

$(NAME_SERV): $(LIB) $(OBJTS_SERV)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
		@rm -f $(OBJTS_SERV) $(OBJTS_CLIENT)
		@rm -f $(LIBFT_DIRECTORY)/*.o

fclean: clean
		@rm -f $(NAME_SERV) $(NAME_CLIENT)
		@rm -f $(LIBFT_DIRECTORY)/libft.a

re : fclean all

.PHONY: all, clean, fclean, re
