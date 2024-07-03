# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgomez-z <cgomez-z@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/03 20:13:13 by cgomez-z          #+#    #+#              #
#    Updated: 2024/07/03 21:51:19 by cgomez-z         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#<------------->CONFIG<------------->

NAME = minitalk
CC = cc
CFLAGS = -Wall -Werror -Wextra

#<------------->FILES<------------->

CFILES = $(shell ls *.c)
OFILES = $(CFILES:.c=.o)

#<------------->RULES<------------->

all: $(NAME)

%.o:%.

$(NAME):


#<------------->PHONY<------------->

clean:
	$(RM) %(OFILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all
