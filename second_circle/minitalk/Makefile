# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgomez-z <cgomez-z@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/03 20:13:13 by cgomez-z          #+#    #+#              #
#    Updated: 2024/07/25 19:19:46 by cgomez-z         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#<------------->CONFIG<------------->

SERVER = server
CLIENT = client
CC = cc
CFLAGS = -Wall -Werror -Wextra -g

#<------------->FILES<------------->

#CFILES = server.c client.c
#OFILES = $(CFILES:.c=.o)

#<------------->RULES<------------->

all: make_libs $(SERVER) $(CLIENT)

make_libs:
	@make -C printf --no-print-directory

$(SERVER): server.c printf/libftprintf.a
	cc server.c printf/libftprintf.a -o $@ 

$(CLIENT): client.c printf/libftprintf.a
	cc client.c printf/libftprintf.a -o $@

%.o:%.c Makefile printf/ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

#$(NAME): $(OFILES)
#	$(CC) $(CFLAGS) $(OFILES) -o $(NAME)

#<------------->PHONY<------------->

clean:
	$(RM) $(SERVER) $(CLIENT) #$(OFILES)
	@make clean -C ./printf

fclean: clean
#	$(RM) $(NAME)

re: fclean all

.PHONY: all cl fclean re
