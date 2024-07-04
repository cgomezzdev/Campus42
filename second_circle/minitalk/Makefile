# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgomez-z <cgomez-z@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/03 20:13:13 by cgomez-z          #+#    #+#              #
#    Updated: 2024/07/04 18:26:37 by cgomez-z         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#<------------->CONFIG<------------->

NAME = minitalk
CC = cc
CFLAGS = -Wall -Werror -Wextra

#<------------->FILES<------------->

CFILES = server.c client.c
OFILES = $(CFILES:.c=.o)

#<------------->RULES<------------->

all: $(NAME)

%.o:%.c minitalk.h Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) -o $(NAME)


#<------------->PHONY<------------->

clean:
	$(RM) $(OFILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all cl fclean re
