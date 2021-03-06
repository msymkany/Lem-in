#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msymkany <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/28 17:05:55 by msymkany          #+#    #+#              #
#    Updated: 2017/05/13 20:30:28 by msymkany         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = lem-in

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

FIL_I = ./includes/len_in.h
INCLUDES = -I $(FIL_I)

SOURCE = lem-in.c \
        ft_error.c \
        managing_lists.c \
        init_structure.c \
        test_print.c \
        validate_ant_num.c \
        validate_rooms.c \
        validate_rooms_2.c \
        validate_links.c \
        all_ways_finding.c \
        ants_race.c \
        ants_race_2.c \
        compose_ways.c \
        compose_ways_2.c \
        find_best_way_combo.c \

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