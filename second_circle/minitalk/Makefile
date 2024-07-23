# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgomez-z <cgomez-z@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/03 20:13:13 by cgomez-z          #+#    #+#              #
#    Updated: 2024/07/23 20:38:33 by cgomez-z         ###   ########.fr        #
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

all: $(SERVER) $(CLIENT)


$(SERVER): server.c
	cc server.c -o $@

$(CLIENT): client.c
	cc client.c -o $@

#%.o:%.c minitalk.h Makefile
#	$(CC) $(CFLAGS) -c $< -o $@
#
#$(NAME): $(OFILES)
#	$(CC) $(CFLAGS) $(OFILES) -o $(NAME)


#<------------->PHONY<------------->

clean:
	$(RM) $(SERVER) $(CLIENT) #$(OFILES)

fclean: clean
#	$(RM) $(NAME)

re: fclean all

.PHONY: all cl fclean re
