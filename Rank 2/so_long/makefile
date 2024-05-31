# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 11:56:43 by maugusto          #+#    #+#              #
#    Updated: 2024/05/27 15:15:01 by maugusto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long

CC := cc

CFLAGS := -Wall -Wextra -Werror -g -Iheaders/

SOURCE := game/*.c
LIBFT := libft/*.c
PRINTF := libft/printf/*.c
GETNEXTLINE := libft/get_next_line/*.c
LIBRARY := -Lminilibx-linux -lmlx -lX11 -lXext -lm
MINILIBX := minilibx-linux/

all:
	make -C $(MINILIBX)
	$(CC) $(CFLAGS) $(SOURCE) $(LIBFT) $(PRINTF) $(GETNEXTLINE) $(LIBRARY) -o $(NAME)

clean:

fclean: clean
	make clean -C $(MINILIBX)
	rm -rf $(NAME)

re: fclean all


# SOURCES = server.c client.c
# OBJECTS = $(SOURCES:.c=.o)

# CC = cc
# CFLAGS = -Wall -Wextra -Werror
# LIBRARY := -Lminilibx -lmlx -framework OpenGL -framework AppKit
# MINILIBX := minilibx/

# all: server client

# server: server.o libft/libft.a
# 	$(CC) -o $@ $< -Llibft -lft

# %.o: %.c
# 	$(CC) -c $(CFLAGS) $< -o $@

# libft/libft.a:
# 	make -C libft

# clean:
# 	rm -f $(OBJECTS)
# 	make -C libft clean
	
# fclean: clean
# 	rm -f server client
# 	make -C libft fclean

# re: fclean all

# .PHONY: all clean fclean re
