# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgomez-z <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/06 21:19:09 by cgomez-z          #+#    #+#              #
#    Updated: 2024/06/08 19:33:47 by cgomez-z         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#<------------->CONFIG<------------->

NAME = fractol
CC = gcc
LIBMLX = ./minilibx-linux/libmlx.a# depeds on where you decided to put your mlx library.
CFLAGS  = -Wall -Werror -Wextra -O3 -g -I$(INC) -I${INCFT} -Iinclude# C Flags (gcc) & linking. "-Iinclude" if you created the folder "include" to put your project headers"
LFLAGS  = -L$(LIBMLX) -lmlx -lft# if you decided to install libmlx.a locally you don't need "-L$(LIBMLX) -lmlx" the school also has it locally as well...
#CFLAGS = -Wall -Werror -Wextra #-fsanitize=address

#<------------->FILES<------------->

HEADER = fractol.h
C_FILES = fractol.c str_utiles.c
O_FILES = $(C_FILES:.c=.o)

#<------------->RULES<------------->

all: $(LIBMLX) $(NAME)

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(O_FILES) $(LIBMLX)
	$(CC) $(CFLAGS) $(O_FILES) -o $(NAME)

#<------------->PHONY<------------->

clean:
	$(RM) $(O_FILES)
	@make clean -c ./minilibx-linux

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBMLX)

re: fclean all

.PHONY: all clean fclean re

