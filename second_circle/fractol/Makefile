# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgomez-z <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/06 21:19:09 by cgomez-z          #+#    #+#              #
#    Updated: 2024/07/02 21:29:18 by cgomez-z         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#<------------->CONFIG<------------->

NAME = fractol
CC = cc
CFLAGS  = -Wall -Wextra -Werror -g -O2 -I/usr/include -Imlx_linux -fsanitize=leak
LFLAGS  = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz 

#<------------->FILES<------------->

HEADER = fractol.h
C_FILES = fractol.c fractol_init.c fractol_render.c fractol_str_utils.c fractol_utils.c \
		  fractol_handler.c fractol_atod.c
O_FILES = $(C_FILES:.c=.o)

#<------------->RULES<------------->

all: make_libs $(NAME) 

make_libs:
	@make -C mlx_linux --no-print-directory
	
%.o:%.c $(HEADER) Makefile mlx_linux/libmlx_Linux.a
	@echo "Compiling...> $<"
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(O_FILES)
	@echo "Compiling file>"
	$(CC) $(O_FILES) $(LFLAGS) -o $(NAME)
	
#<------------->PHONY<------------->

clean:
	$(RM) $(O_FILES) $(LIBMLX) 
	@make clean -C ./mlx_linux

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

