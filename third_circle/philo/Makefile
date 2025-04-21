# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/16 13:02:57 by cgomez-z          #+#    #+#              #
#    Updated: 2025/04/21 20:39:15 by cgomez-z         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Werror -Wextra -Wall -g -fsanitize=thread

#<------------->FILES<------------->

HEADER = philo.h
C_FILES = philo.c routine.c 
O_FILES = $(C_FILES:.c=.o)

#<------------->RULES<------------->

all: $(NAME)

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(O_FILES)
	$(CC) $(CFLAGS) $(O_FILES) -o $(NAME) -lpthread

#<------------->PHONY<------------->

clean:
	$(RM) $(O_FILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
