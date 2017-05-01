#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msymkany <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/28 17:05:55 by msymkany          #+#    #+#              #
#    Updated: 2017/04/28 17:10:19 by msymkany         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = lem-in

CC = gcc
CFLAGS = -Wall -Wextra -Werror

FIL_I = ./includes/len_in.h
INCLUDES = -I $(FIL_I)

SOURCE = lem-in.c \
            read_input.c \

OBJECTS = $(SOURCE:.c=.o)

LIBFT_DIR = ./libft/

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT_DIR)libft.a
		$(CC) $(FL) $(OBJECTS) -o $(NAME) -L$(LIBFT_DIR) -lft

%.o: %.c
	$(CC) $(FL) -c $< -o $@

$(LIBFT_DIR)libft.a:
		make -C $(LIBFT_DIR)

.PHONY: clean fclean re

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJECTS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all