# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgomez-z <cgomez-z@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/03 20:13:13 by cgomez-z          #+#    #+#              #
#    Updated: 2024/07/28 20:42:16 by cgomez-z         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#<------------->CONFIG<------------->

SERVER = server
CLIENT = client
PRINTF_A = printf/libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -g

#<------------->FILES<------------->

CFILES = client.c
OCFILES = $(CFILES:.c=.o)
SFILES = server.c
OSFILES = $(SFILES:.c=.o)

#<------------->RULES<------------->

%.o:%.c 	Makefile $(SERVER) %(CLIENT)
			$(CC) $(CFLAGS) -c $< -o $@

all: make_libs $(SERVER) $(CLIENT)

make_libs:
	@make -C printf --no-print-directory

$(SERVER): $(OSFILES) $(PRINTF_A)
	$(CC) $(OSFILES) $(PRINTF_A) -o $@ 

$(CLIENT): $(OCFILES) $(PRINTF_A)
	$(CC) $(OCFILES) $(PRINTF_A) -o $@

#<------------->PHONY<------------->

clean:
	$(RM) $(SERVER) $(CLIENT) $(OCFILES) $(OSFILES)
	@make clean -C ./printf

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all cl fclean re
