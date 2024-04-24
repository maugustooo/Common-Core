# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 12:18:36 by gude-jes          #+#    #+#              #
#    Updated: 2024/04/24 14:17:23 by maugusto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror
FLAGLIB			= -rcs

SRCS			=	ft_printf.c ft_put_hex.c ft_putpointer.c ft_prints.c\
					
OBJS = $(SRCS:.c=.o)

LIBFT_DIR		= ./libft
LIBFT			= ./libft/libft.a

all:			$(NAME)

$(NAME): $(LIBFT) $(OBJS)		
	@echo "Linking $(NAME)"
	@cp $(LIBFT) $(NAME)
	@ar $(FLAGLIB) $(NAME) $(OBJS)
	@ranlib $(NAME)

$(LIBFT): $(LIBFT_DIR)
	@echo "Compiling libft"
	@$(MAKE) -C $(LIBFT_DIR)

%.o: $(SRC)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling $<"

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(RM) $(OBJS)

fclean:		clean
			@$(MAKE) fclean -C $(LIBFT_DIR)
			@$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus
