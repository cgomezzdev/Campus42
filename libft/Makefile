# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 19:45:04 by cgomez-z          #+#    #+#              #
#    Updated: 2024/02/17 18:38:58 by cgomez-z         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########## CONFIG ##########
NAME	= libft.a
HEADER_FILE	= libft.h
CC	= gcc
FLAGS	= -Wall -Wextra -Werror
AR = ar -rcs
########## FILES ##########
C_FILES = ft_atoi.c ft_isprint.c ft_putchar_fd.c ft_striteri.c ft_strnstr.c\
		  ft_bzero.c ft_itoa.c ft_putendl_fd.c ft_strjoin.c ft_strrchr.c\
		  ft_calloc.c ft_memchr.c ft_putnbr_fd.c ft_strlcat.c ft_strtrim.c\
		  ft_isalnum.c ft_memcmp.c ft_putstr_fd.c ft_strlcpy.c ft_substr.c\
		  ft_isalpha.c ft_memcpy.c ft_split.c ft_strlen.c ft_tolower.c\
		  ft_isascii.c ft_memmove.c ft_strchr.c ft_strmapi.c ft_toupper.c\
		  ft_isdigit.c ft_memset.c ft_strdup.c ft_strncmp.c

C_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c\
		  ft_lstlast_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c\
		  ft_lstiter_bonus.c ft_lstadd_back_bonus.c ft_lstmap_bonus.c

OBJS = $(C_FILES:.c=.o)

BOBJS = $(C_BONUS:.c=.o)

########## RULES ##########
all:  $(NAME)

%.o: %.c $(HEADER_FILE) Makefile
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus:$(BOBJS)
	$(AR) $(NAME) $(BOBJS)
	touch bonus

clean: 
	$(RM) $(OBJS) $(BOBJS)
	$(RM) bonus

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
