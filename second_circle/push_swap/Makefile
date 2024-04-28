# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/27 18:28:10 by cgomez-z          #+#    #+#              #
#    Updated: 2024/04/28 18:26:39 by cgomez-z         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#<------------->CONFIG<------------->

NAME = push_swap.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar -rcs

#<------------->FILES<------------->

HEADER = push_swap.h
C_FILES = push_swap.c
O_FILES = $(C_FILES:.c=.o)

#<------------->RULES<------------->

all: $(NAME)

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(O_FILES)
	$(AR) $(NAME) $(O_FILES)

#<------------->PHONY<------------->

clean:
	$(RM) $(O_FILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

#<------------->8<------------->
