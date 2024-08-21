# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/27 18:28:10 by cgomez-z          #+#    #+#              #
#    Updated: 2024/08/15 22:48:47 by cgomez-z         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#<------------->CONFIG<------------->

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address

#<------------->FILES<------------->

HEADER = push_swap.h
C_FILES = push_swap.c ft_atoi.c ft_isdigit.c ft_check_dupe.c lst_utils.c ft_printlst.c \
	  sort_short.c short_utils.c swap.c rotate.c push.c radix_sort.c
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
