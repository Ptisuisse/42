# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 10:00:48 by lvan-slu          #+#    #+#              #
#    Updated: 2025/01/24 10:00:50 by lvan-slu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.cpp \
		ClapTrap.cpp \
		ScavTrap.cpp \
		FragTrap.cpp \

OBJS = $(SRCS:.cpp=.o)
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
EXEC = fragtrap
NAME = $(EXEC)

$(NAME): $(OBJS)
	$(CXX) -o $(EXEC) $(OBJS)

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all, clean, fclean, re
