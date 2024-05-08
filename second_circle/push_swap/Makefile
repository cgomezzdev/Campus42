# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/27 18:28:10 by cgomez-z          #+#    #+#              #
#    Updated: 2024/05/08 19:35:59 by cgomez-z         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#<------------->CONFIG<------------->

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra

#<------------->FILES<------------->

HEADER = push_swap.h
C_FILES = push_swap.c ft_atoi.c ft_isdigit.c
O_FILES = $(C_FILES:.c=.o)

#<------------->RULES<------------->

all: $(NAME)

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(O_FILES)
	$(CC) $(CFLAGS) $(O_FILES) -o $(NAME)

#<------------->PHONY<------------->

clean:
	$(RM) $(O_FILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

#<------------->8<------------->
