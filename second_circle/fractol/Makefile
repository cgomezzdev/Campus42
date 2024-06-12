# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgomez-z <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/06 21:19:09 by cgomez-z          #+#    #+#              #
#    Updated: 2024/06/12 19:38:33 by cgomez-z         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#<------------->CONFIG<------------->

NAME = fractol
CC = gcc
CFLAGS  = -I/usr/include -Iminilibx-linux -O3# C Flags (gcc) & linking. "-Iinclude" if you created the folder "include" to put your project headers"
LFLAGS  = -Lminilibx-linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -Iminilibx-linux #if you decided to install libmlx.a locally you don't need "-L$(LIBMLX) -lmlx" the school also has it locally as well...
#CFLAGS = -Wall -Werror -Wextra #-fsanitize=address

#<------------->FILES<------------->

HEADER = fractol.h
C_FILES = fractol.c str_utiles.c
O_FILES = $(C_FILES:.c=.o)

#<------------->RULES<------------->

all: make_libs $(NAME) 

make_libs:
	@make -C mlx_linux --no-print-directory
	
%.o:%.c $(HEADER) Makefile mlx_linux/libmlx_Linux.a
	@echo "Compiling...> $<"
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(O_FILES)
	@echo "Compiling file>"
	$(CC) $(O_FILES) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	
#$(NAME):
#	@echo "$(NAME) compiled"

#<------------->PHONY<------------->

clean:
	$(RM) $(O_FILES) $(LIBMLX) 
	@make clean -C ./mlx_linux

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

